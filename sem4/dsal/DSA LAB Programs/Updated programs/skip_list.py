import random 
  
class Node: 
    
    def __init__(self, key, level): 
        self.key = key 
		# list to hold addresses to node of different level
        self.next = [None]*(level+1) 
  
class SkipList: 
   
    def __init__(self, max_lvl, P):        
		# Maximum level for this skip list 
		    self.MAXLVL = max_lvl 

		# P is the fraction of the nodes with level 
		# i references also having level i+1 references 
		    self.P = P 

		# create header node and initialize key to -1 
		    self.header = self.createNode(self.MAXLVL, -1) 

		# current level of skip list 
		    self.level = 0
		
     # Create new node 
    def createNode(self, lvl, key): 
        n = Node(key, lvl) 
        return n 
     
	 # create random level for node
    def randomLevel(self): 
        lvl = 0
        while random.random()<self.P and lvl<self.MAXLVL:
              lvl += 1
        return lvl 
		
    # Insert key
    def insertElement(self, key): 
        update = [None]*(self.MAXLVL+1) 
        current = self.header 
  
        ''' 
        start from highest level of skip list move the current reference forward while key  
        is greater than key of node next to current 
		Otherwise inserted current in update and move one level down and continue search 
        '''
        for i in range(self.level, -1, -1): 
            while current.next[i] and current.next[i].key < key: 
                current = current.next[i] 
            update[i] = current 
  
       #level 0 is reached and forward refernce to right which is the correct position for insertion
        current = current.next[0] 
  
        ''' 
        if current is NULL that means we have reached to end of the level or current's key is not equal 
           to key to insert that means we have to insert node between update[0] and current node 
       '''
        if current == None or current.key != key: 
            rlevel = self.randomLevel() 
  
            ''' 
            If random level is greater than list's current level (node with highest level inserted in  
            list so far), initialize update value with reference to header for further use 
            '''
            if rlevel > self.level: 
                for i in range(self.level+1, rlevel+1): 
                    update[i] = self.header 
                self.level = rlevel 
  
            n = self.createNode(rlevel, key) 
			
            #insert the node and update all references
            for i in range(rlevel+1): 
                n.next[i] = update[i].next[i] 
                update[i].next[i] = n 
  
            print("Successfully inserted key {}".format(key)) 
 
    #Search the element
    def searchElement(self, key):  
        current = self.header 

        for i in range(self.level, -1, -1): 
            while(current.next[i] and current.next[i].key < key): 
                current = current.next[i] 
  
        current = current.next[0] 
  
        if current and current.key == key: 
            print("Entered Key Found ", key) 
        else:
            print("Entered Key Not Found ")
  
  
    # Display the list levelwise
    def displayList(self): 
        print("\nSkip List Is : ") 
        head = self.header 
        for lvl in range(self.level+1): 
            print("Level {}: ".format(lvl), end=" ") 
            node = head.next[lvl] 
            while(node != None): 
                print(node.key, end=" ") 
                node = node.next[lvl] 
            print("") 
  
def main(): 
    lst = SkipList(3, 0.5) 
    
    n=int(input("Enter total number of element"))

    for i in range(0,n):
        temp=int(input("Enter the Element"))
        lst.insertElement(temp)

    lst.displayList() 
  
    temp=int(input("Enter Element for searching"))
    lst.searchElement(temp) 
  
  
main() 