#include <stdio.h>
#include <stdlib.h>

#define MAX_QSIZE 50

#define R 5 //no of rows in the dungeon
#define C 5 //no of cols in the dungeon
/* our dungeon will look like this 

S . . # .
. # . . .
. # # . .
. . # . #
. E . . #

S is the start point 
E is the ending point 
# is the obstacle 
. is the free space to make a move on 
*/ 
char M[5][5]={
			{'S','.','.','#','.'},
			{'.','#','.','.','.'},
			{'.','#','#','.','.'},
			{'.','.','#','.','#'},
			{'.','E','.','.','#'}};

int sr=0;
int sc=0; //start vertex row and column 



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
int bfs_shortest_path();
			
//MAIN FUNCTION  
int main(){
	int i;
	printf("Shortest path in the dungeon is %d steps long\n",bfs_shortest_path());
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


int bfs_shortest_path(){
	int i,rr,cc;
	//variables used to track the no of steps taken 
	int move_count=0;
	int nodes_left_in_layer=1;
	int nodes_in_next_layer=0;
	
	//direction arrays 
	int dr[]={-1,1,0,0};
	int dc[]={0,0,1,-1};

	int reached_end=0;
	struct Queue* rq=create_queue(); //empty row queue
	struct Queue* cq=create_queue(); //empty column queue 
	
	int** visited=(int **)malloc(sizeof(int *)*R);//keeps tracks of the visited spots 
	for(i=0;i<R;i++){
		visited[i]=(int *)calloc(C,sizeof(int));
	}
	
	visited[sr][sc]=1;
//enqueue start row index and start column index
	enqueue(rq,sr);
	enqueue(cq,sc); 

	
	while(!is_empty(rq)){
		int r=dequeue(rq);
		int c=dequeue(cq);
		printf("Visited %d-%d\n",r,c);
		if (M[r][c]=='E'){
			reached_end=1;
			break;
		}
		for(i=0;i<4;i++){
			rr=r+dr[i];
			cc=c+dc[i];
	
			if(rr<0 || cc<0) continue;
			if(rr>=R || cc>=C) continue;

			//skip visited locations or blocked cells 
			if (visited[rr][cc]==1) continue;
			if (M[rr][cc]=='#') continue;
			enqueue(rq,rr);
			enqueue(cq,cc);
			visited[rr][cc]=1;
			nodes_in_next_layer++;
		}
		nodes_left_in_layer--;
		if(nodes_left_in_layer==0){
			nodes_left_in_layer=nodes_in_next_layer;
			nodes_in_next_layer=0;
			move_count++;
		}
	}
	if(reached_end==1) return move_count;
	return -1;
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

