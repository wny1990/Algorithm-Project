#include <iostream>
#include <ctime>
#include <cstdlib>
#include "heap.hpp"
#include "vertex.hpp"
#include "graph.hpp"
#define KEY_TYPE int
#define VNUM 6000
using namespace std;
void init_graph1(graph<KEY_TYPE,VNUM> g0);
void init_graph2(graph<KEY_TYPE,VNUM> g0);

int main(){
	
//	heap<vertex<KEY_TYPE>,VNUM,value_fun<KEY_TYPE>,KEY_TYPE> h0;
	
	graph<KEY_TYPE,VNUM> g1,g2;
	init_graph1(g1);
	init_graph2(g2);

	return 0;
}

void init_graph1(graph<KEY_TYPE,VNUM> g0)
{	
	int i,count,ran_num;

	for(i = 1 ; i <= VNUM ; i++)
		g0.add_vertex(i,0);

	srand((unsigned)time(0));

	for (i = 1 ; i <= VNUM ; i++)
	{
		count = 0;
		while (count < 6) 
		{
			ran_num = (rand() % VNUM) +1;
			if (!g0.is_edge(i,ran_num)) 
			{
	//			cout <<"edge: " << i<<" "<<  ran_num << endl;
				g0.add_edge(i,ran_num,2);
				count++;
			}
		}
	}

return;
}
void init_graph2(graph<KEY_TYPE,VNUM> g0)
{
	int i,j,count,ran_num;
	for (i = 1 ; i <= VNUM ; i++)
		for (j = i ; j <= VNUM ; j++)
		{
			ran_num = rand() % 5;
			//20% possibility
			if (ran_num == 0 && i != j) 
			{
			//	cout <<"edge: " << i<<" , "<<  j<< endl;
				g0.add_edge(i,j,2);
			count=1;
			}
		}

return;
}
/*	g1.add_edge(2,3,2.2);
	g1.add_edge(1,3,3);
	g1.add_edge(4,7,4);

	cout <<"vcount: " << g1.get_v_count() << endl;
	cout <<"ecount: " << g1.get_e_count() << endl;
	
	cout <<"2,3: " << g1.is_edge(2,3) << " wt: "<<g1.edge_weight(2,3)<<endl;
	cout <<"3,8: " << g1.is_edge(3,8) << " wt: "<< g1.edge_weight(3,8)<<endl;
	cout <<"5,8: " << g1.is_edge(5,8) << " wt: "<< g1.edge_weight(5,8)<<endl;
	cout <<"1,3: " << g1.is_edge(3,1) << " wt: "<< g1.edge_weight(3,1)<<endl;
	cout << endl;

	h0.insert(g1.get_v(1));
	h0.insert(g1.get_v(2));
	h0.insert(g1.get_v(3));
	h0.insert(g1.get_v(4));
	h0.insert(g1.get_v(5));
	h0.insert(g1.get_v(6));
	h0.insert(g1.get_v(7));
	h0.insert(g1.get_v(8));
	
	cout <<"min:"<< h0.min().get_key() << endl;
	cout <<"size:"<< h0.size() << endl;

	
	for (i=1;i<=h0.size();i++) cout << h0.index(i).get_name()<< " , "<<h0.index(i).get_key() <<endl;
	for (j=1;h0.size();j++)
	{	
		h0.del_min();
		cout <<"after remove:"<< endl;
		for (i=1;i<=h0.size();i++) cout << h0.index(i).get_name()<< " , "<<h0.index(i).get_key() <<endl;
	}
*/
