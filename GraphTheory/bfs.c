#include <stdio.h>
#include <stdlib.h>

#define MAX_QSIZE 50
struct Node{
	int vertex;
	struct Node* next;
};

struct Graph{
	int num_vertices;
	struct Node** adj_list;
	int *visited;
};
struct Graph* create_graph(int vertices);
struct Node* create_node(int v); //create a node 
void add_edge(struct Graph* graph,int s,int d); //add edge to the graph from source s to destination d  
void print_graph(struct Graph* graph);//prints the graph


/*Defining some queue parameters */
struct Queue{
	int items[MAX_QSIZE];
	int front;
	int rear;
};

struct Queue* create_queue();
void enqueue(struct Queue* q,int);
int dequeue(struct Queue* q);
int is_empty(struct Queue* q);
int return_front(struct Queue* q);
void print_queue(struct Queue* q);

/* now let's move on to BFS shall we */
int* bfs(struct Graph* graph,int start_vertex);
			
//MAIN FUNCTION  
int main(){
	int i;
	struct Graph* graph=create_graph(4);//4 being the no of vertices
	int *return_path;
	add_edge(graph,0,1);
	add_edge(graph,1,2);
	add_edge(graph,0,3);
	add_edge(graph,1,3);

	print_graph(graph);
	return_path=bfs(graph,0);
	
	printf("Breadth first search Path:\n");
	for(i=0;i<graph->num_vertices;i++){
		printf("%d->",return_path[i]);
	}
	return 0;
}

//Creates a queue
struct Queue* create_queue(){
	struct Queue* q=malloc(sizeof(struct Queue));
	q->front=-1;
	q->rear=-1;
	return q;
}


//checks if q is empty 
int is_empty(struct Queue* q){
	if(q->rear==-1){
		return 1;
	}
	else{
		return 0;
	}
}

//add elements to the queue
void enqueue(struct Queue* q,int value){
	if((q->rear+1)%MAX_QSIZE==q->front){
		printf("Queue is full mate!");
	}
	else if(is_empty(q)){
			q->rear=0;
			q->front=0;
	}
	else{
		q->rear=(q->rear+1)%MAX_QSIZE;
	}
	q->items[q->rear]=value;
}

//dequeue element from the queue 
int dequeue(struct Queue* q){
	int return_value;
	if(is_empty(q)){
		return -1;
	}
	else if (q->front==q->rear){
		return_value=q->items[q->front];
		q->front=-1;
		q->rear=-1;
	}
	else{
		return_value=q->items[q->front];
		q->front=(q->front+1)%MAX_QSIZE;
	}
	return return_value;
	
}

//return front element of the queue
int return_front(struct Queue* q){
	return q->items[q->front];
}

void print_queue(struct Queue* q){
	int i;

	printf("Queue :\t");
	for(i=q->front;i<=q->rear;i++){
		printf("%d\t",q->items[i]);
	}
	printf("\n");
}

//Graph related functions 
//create a node 
struct Node* create_node(int v){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->vertex=v;
	new_node->next=NULL;
	return new_node;
}

//create a graph 
struct Graph* create_graph(int vertices){
	struct Graph* graph=malloc(sizeof(struct Graph));
	graph->num_vertices=vertices;
	graph->adj_list=malloc(vertices*sizeof(struct Node*));
	graph->visited=malloc(vertices*sizeof(int));
	
	int i;
	for(i=0;i<vertices;i++){
		graph->adj_list[i]=NULL;
		graph->visited[i]=0;
	}
	return graph;
}

//add edge 
void add_edge(struct Graph* graph,int s,int d){
	//adds edge from s to d 
	struct Node* new_node=create_node(d);
	new_node->next=graph->adj_list[s];
	graph->adj_list[s]=new_node;
	
	//adds edge from d to s 
	new_node=create_node(s);
	new_node->next=graph->adj_list[d];
	graph->adj_list[d]=new_node;
}

//print the graph 
void print_graph(struct Graph* graph){
	int v;
	for(v=0;v<graph->num_vertices;v++){
		struct Node* temp=graph->adj_list[v];
		printf("Vertex %d:\n",v);
		while(temp){
			printf("%d -> ",temp->vertex);
			temp=temp->next;
		}
		printf("\n");
	}
}

int* bfs(struct Graph* graph,int start_vertex){
	struct Queue* q=create_queue();
	int *path=malloc(sizeof(int)*graph->num_vertices);
	int i=0;//iterator for path
	graph->visited[start_vertex]=1;
	
	enqueue(q,start_vertex);
	while(!is_empty(q)){
		print_queue(q);
		int current_vertex=dequeue(q);
		printf("Visited %d\n",current_vertex);
		path[i++]=current_vertex;
		
		struct Node* neighbour=graph->adj_list[current_vertex];
		while(neighbour!=NULL){
			int adj_vertex=neighbour->vertex;
			
			if (graph->visited[adj_vertex]==0){
				graph->visited[adj_vertex]=1;
				enqueue(q,adj_vertex);
			}
			neighbour=neighbour->next;
		}
	}
	return path;
}
		
// struct Node** solve(struct Node* s,struct Graph* graph){
//     enqueue(s);
//     int* visited=(int *)calloc(4,sizeof(int));
//     int i; //iterator 
//     struct Node* neighbour;
//     struct Node* node;
//     visited[s->vertex]=1;
//     struct Node* prev[50];
//     while(is_empty()){
//         dequeue();
//         node=return_front();
//         neighbour=graph->adj_list[node->vertex];
//         while(neighbour!=NULL){
//             if(visited[neighbour->vertex]==0){
//                 enqueue(neighbour);
//                 visited[neighbour->vertex]=1;
//                 prev[neighbour->vertex]=node;
//             }
//         }
//         
//     return prev;
//     }
// }
//        
// int* reconstruct_path(struct Node* s,struct Node* e,struct Node* prev[]){
//     int* path=(int *)malloc(sizeof(int)*4);
//     int* return_path=(int *)malloc(sizeof(int)*4);
//     int path_size;
//     struct Node* at; //iterator
//     int count=0,i;
//     for(at=e;at!=NULL;at=prev[at->vertex]){
//         path[count]=at->vertex;
//     }
//     path_size=sizeof(path)/sizeof(path[0]);
//     //reverse path 
//     for(i=0;i<path_size;i++){
//        return_path[i]=path[path_size-i];
//     }
//     if(return_path[0]==s->vertex){
//         return return_path;
//      }
//     return NULL;
// }
//     
// int* bfs(struct Node* s,struct Node* e,struct Graph* graph){
//     struct Node** prev=malloc(sizeof(struct Node*)*50);;
//     prev=solve(s,graph);
//     return reconstruct_path(s,e,prev);
// }

