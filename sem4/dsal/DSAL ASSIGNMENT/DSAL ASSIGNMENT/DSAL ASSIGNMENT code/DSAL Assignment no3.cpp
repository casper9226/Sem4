/*There are flight paths between cities. If there is a flight between city A and city B
then there is an edge between the cities. The cost of the edge can be the time that
flight takes to reach city B from A, or the amount of fuel used for the journey.
Represent this as a graph. The node can be represented by airport name or name
of the city. Use adjacency list representation of the graph or use adjacency matrix
representation of the graph. Check whether the graph is connected or not. Justify
the storage representation used.*/


#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;
using std::endl;
const int max_cities = 10;
namespace mine
{
    class node 
    { 
        public:
            string air_name;
            int time;
            node* next;
        node()
        {
            this->air_name = "" ;
            this->time = -1 ;
            this->next = nullptr;
        } 
        node(const string& airport)
        {
            this->air_name = airport;
            this->next = nullptr;
        }
        node(const string& airport,const int& mins)
        {
            this->air_name = airport;
            this->time=mins;
            this->next = nullptr;
        }
    };
    class Graf
    {
        private:
            int matrix[max_cities][max_cities];
            string city[max_cities];
            node *head_ptr[max_cities];
            node* temp;
            int n_cities;
        public:
            Graf()
            {
                for(int i = 0 ; i < max_cities; i ++ )
                {
                for(int j = 0 ; j< max_cities ; j ++ )
                {
                    if(i==j)
                        this->matrix[i][j] = -1;
                } 
                }
            }
        void input_graph();
        void list_initialiser();
        void display_matrix();
        void display_list();
    };
}

int  main()
{   
    using namespace mine;
    Graf *graf = new Graf();

    int choice;
    cout<<"Welcome"<<endl;
    int t = 0 ;
    while(t<7)
    {
    cout<<"Enter your Choice:\n1)Enter the Graph.\n2)Display Adjacency Matrix.\n3)Display Adjecency List.\n4)Exit "<<endl;
    cin>>choice;
    switch (choice)
    {
    case 1:
        graf->input_graph();
        break;
    case 2:
        graf->display_matrix();
        break;
    case 3:
        graf->display_list();
        break;
    case 4:
        exit(0);
    default:
        cout<<"WOW"<<endl;
        t--;
        break;
    }
    t++;
    }
    
  
    return 0;
}
void mine::Graf::input_graph()
{
    cout<<"Enter the Number of cities : ";
    cin>>this->n_cities;
    cout<<"Enter the name of the cities(with space): ";
    for ( int i = 0 ; i < n_cities ; i ++ )
    {
        cin>>this->city[i];
    }
    for( int i = 0 ; i <n_cities ; i ++ )
    { 
        for ( int j = 0; j<n_cities ; j++)
        {

            if ( i==j)
                continue;
            else
            {   char choice;
                cout<<"Is there a path between : "<<city[i]<<"-> "<<city[j]<<" Enter y or n : ";
                cin>>choice;
                if(choice =='y')
                {
                    cout<<"How much time does it take ? :";
                    cin>>matrix[i][j];
                }
                else if(choice =='n')
                {
                    matrix[i][j]=0;
                }
                else
                {
                    cout<<"Invalid input"<<endl;
                }
                
            }
        }
    }
    this->list_initialiser();
}

void mine::Graf::list_initialiser()
{
    for(int i = 0 ; i < n_cities ; i++)
    {
        this->head_ptr[i] = new node(city[i]);
    }
    for ( int i = 0 ; i < n_cities ; i++)
    {
        for ( int j = 0 ; j < n_cities ; j++)
        {
            if(matrix[i][j]>0)
            {   
                
                node *t = new node(city[j],matrix[i][j]);
                if(head_ptr[i]->next == NULL)
                    head_ptr[i]->next=t;
                else 
                {
                    temp = head_ptr[i];
                    while(temp->next !=NULL)
                    {
                        temp= temp->next;
                    }
                    temp->next = t;
                }    
                
            }
        }
    }


}

void mine::Graf::display_matrix()
{
    cout<<"\n";
    for(int i = 0; i < n_cities ; i++)
    { cout<<"\t "<<city[i];}
    cout<<endl;
    for (int i = 0 ; i < n_cities;i++)
    {
        cout<<city[i];
        for(int j= 0 ; j < n_cities ; j++)
        {   
        if(matrix[i][j]==-1)
        {
            cout<<"\t";
        }
        else
        {
            cout<<" \t";
        }
        cout<<matrix[i][j];
            
        }
        cout<<"\n";
    }
}   

void mine::Graf::display_list()
{
    cout<<"Path and time taken to reach city \n";
    for(int i = 0 ; i< n_cities;i++)
    {
        if(this->head_ptr==NULL)
        {
            cout<<"Abey graph is MT ."<<endl;
        }
        else
        {
            
            
            for(temp = head_ptr[i]->next;temp !=NULL;temp=temp->next)
            {   
                cout<<head_ptr[i]->air_name;
                cout<<"-> "<<temp->air_name<<"\t\t"<<"[ Time required : "<<temp->time<<" ]"<<endl;
            }
        }
    }
}

