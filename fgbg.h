#ifndef fgbg
#define fgbg

void fg(){
	FILE *fp = NULL;
	fp = fopen(paths,"r+");
	int calc,counter = 0,status=0;
	while(1){
		char st[1024];
		fgets(st,200,fp);
		st[0]!=0?counter++:counter;
		if(feof(fp)) break;
		int l = strlen(st+1);
		char store[1024] = {'\0'};
		for(int i=1;st[i]!=' ';i++){
			store[i-1] = st[i];
		}
		int val = calculater(store,strlen(store)+1);
        calc=(input[1][0]!=0?input[1][0]-48:0);
        if (input[1][1]!=0) calc=(calc*10)+input[1][1]-48;
		if(counter==calc){
			printf("inside\n");
			kill(val,SIGCONT);
			int ret=waitpid(val,&status,WUNTRACED);
			break;
		}
	}
	if(counter != calc){
		perror("invalid no of inputs");
	}
	fclose(fp);
}
void bg(){
	FILE *fp = NULL;
	fp = fopen(paths,"r+");
	int calc,counter = 0,status=0;
	while(1){
		char st[1024];
		fgets(st,200,fp);
		st[0]!=0?counter++:counter;
		if(feof(fp)) break;
		int l = strlen(st+1);
		char store[1024] = {'\0'};
		for(int i=1;st[i]!=' ';i++){
			store[i-1] = st[i];
		}
		int val = calculater(store,strlen(store)+1);
        calc=(input[1][0]!=0?input[1][0]-48:0);
        if (input[1][1]!=0) calc=(calc*10)+input[1][1]-48;
		if(counter==calc){
			kill(val,SIGCONT);
			break;
		}
	}
	if(counter != calc){
		perror("invalid no of inputs");
	}
	fclose(fp);
}
#endif
