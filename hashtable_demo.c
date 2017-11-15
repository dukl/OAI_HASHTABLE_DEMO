#include"obj_hashtable.h"
#include"hashtable.h"
#include<stdio.h>
int main(){
    const hash_size_t sizeP=10;
	int key_sizeP=2*sizeof(long);
	long key[2]={208,98};
	long *keyP=key;
	char *dataP= (char *)malloc(sizeof(char));
	char *data = "dukl";
	dataP = data;
	

	obj_hash_table_t *hashtblp=obj_hashtable_create(sizeP,NULL,NULL,NULL,NULL);
	if(hashtblp){
		printf("\nyou have succeeded create your first hashtable!!!\n");
		printf("%d,%d,%s\n\n",hashtblp->name->mlen,hashtblp->name->slen,hashtblp->name->data);
        hashtable_rc_t state = obj_hashtable_insert(hashtblp,keyP,key_sizeP,dataP);
		if(state == HASH_TABLE_OK){
		    hashtable_rc_t dumpState = obj_hashtable_dump_content(hashtblp,hashtblp->name);
			switch(dumpState){
			   case HASH_TABLE_BAD_PARAMETER_HASHTABLE:
				   printf("bad paraneter\n\n");break;
			   case HASH_TABLE_OK:
				   printf("hash_table_ok\n\n");break;
			}
		}
		//obj_hashtable_destroy(hashtblp);
	}else
	    printf("\nI'm sorry!\n\n");

    hashtable_rc_t isExist = obj_hashtable_is_key_exists(hashtblp,keyP,key_sizeP);
	switch(isExist){
		case HASH_TABLE_BAD_PARAMETER_HASHTABLE:
			printf("HASH_TABLE_BAD_PARAMETER_HASHTABLE\n\n");break;
		case HASH_TABLE_BAD_PARAMETER_KEY:
			printf("HASH_BAD_PARANETER_KEY\n\n");break;
		case HASH_TABLE_OK:
			printf("HASH_TABLE_OK\n\n");break;
		case HASH_TABLE_KEY_NOT_EXISTS:
			printf("HASH_TABLE_KEY_NOT_EXISTS\n\n");break;
	}

	long key2[2]={208,98};
	long *keyP2=key2;
    char *dataP2="dukl test";


    obj_hashtable_insert(hashtblp,keyP2,key_sizeP,dataP2);
    hashtable_rc_t isExist2 = obj_hashtable_is_key_exists(hashtblp,keyP2,key_sizeP);
	switch(isExist2){
		case HASH_TABLE_BAD_PARAMETER_HASHTABLE:
			printf("HASH_TABLE_BAD_PARAMETER_HASHTABLE\n\n");break;
		case HASH_TABLE_BAD_PARAMETER_KEY:
			printf("HASH_BAD_PARANETER_KEY\n\n");break;
		case HASH_TABLE_OK:
			printf("HASH_TABLE_OK\n\n");break;
		case HASH_TABLE_KEY_NOT_EXISTS:
			printf("HASH_TABLE_KEY_NOT_EXISTS\n\n");break;
	}

	char *dataRev[2];
	obj_hashtable_get(hashtblp,keyP,key_sizeP,dataRev);
	printf("%s\n\n",dataRev[0]);

    obj_hash_node_t * node;
	hash_size_t       hash;
    hash = hashtblp->hashfunc(keyP,key_sizeP) % hashtblp->size;
	node = hashtblp->nodes[hash];
	while(node){
	  printf("%s\n",node->data);
	  node = node->next;
	}

    return 0;
}

