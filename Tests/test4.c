/*
 * <student name>
 * <student section>
 * <student username>
 * <professor>
 */

void add(node_t **node, node_t **head){
	node_t traverse = head;
	while(head->nextEntry != NULL){
		traverse = traverse->next;	
	}
	traverse->next = node;
}

node_t* readNodeInfo(FILE* input){
	node_t entryLine; 
	while(fscanf(input,"%[^,]%*c","%[^,]%*c","%[^,]%*c","%[^,]%*c",\
			   "%[^,]%*c","%[^,]%*c","%[^,]%*c",\
			   entryLine.last, entryLine.first,\
			   entryLine.bDay.month,\
			   entryLine.bDay.day,\
			   entryLine.bDay.year,\
			   entryLine.song,\
			   entryLine.pastTime,\
			   entryLine.reason)){
	
	}
}                                              

node_t* createList(FILE*, node_t**){

}                                            

void printList(FILE*, node_t*){
	node_t traverse = node;
	puts("LIST INFO:");
	while(traverse->nextEntry != NULL){
		printf("Name:%s\nDate of Birth:%s\nFavorite Song:%s\n"
		       "");	
	}	
}                                                 

void printBorder(FILE*){

}

void deleteList(node_t**){

} 
