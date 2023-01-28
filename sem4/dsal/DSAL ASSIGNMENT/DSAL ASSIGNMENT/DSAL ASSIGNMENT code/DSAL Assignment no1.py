# -*- coding: utf-8 -*-

'''Problem Statement : Consider telephone book database of N , 
   Clients make use of a hash table implementation to quickly look up clients tele number . 
   Make use of a two collsion handling techniques and compare them using number of comparison required . 
   Find set of telephone number '''

#Function to calculate the address of the element according to the hash function
def HashFunction(name,tele,N):
    return tele%N


#Function to display the hash table 
def display(table):
    for i in range(len(table)):
        print(i,end =" ")

        for j in table[i]:
            print("-->", end = " ") 
            print(j, end = " ") 

        print()


def main():

    size = int(input("Enter the size of the database you want to store: "))
    print("_"*50)
    print()

    HashTable =[[]for _ in range (size)]

    for i in range (size):

        print("Enter the name of the : ",i+1," Person : ",end = " ")
        Name=input()
        print()
        print("Enter the telephone number for ", Name,":",end =" ")
        Telephone_No=int(input())
        print()

        #Adding the values to the hash table and sorting out the collision 
        address=HashFunction(Name,Telephone_No,size)
        Details=" [ Name:"+Name+" , "+"Tele_No:"+str(Telephone_No)+" ]"

        HashTable[address].append(Details)
    print("_"*50)
    print()
    display(HashTable)

if __name__ == '__main__':
  main()