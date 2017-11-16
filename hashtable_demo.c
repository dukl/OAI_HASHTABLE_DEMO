#include"obj_hashtable.h"
#include"hashtable.h"
#include"esm_data.h"
#include"3gpp_23.003.h"
#include<stdio.h>
int main(){
    const hash_size_t sizeP=10;
	int key_sizeP=2*sizeof(long);
//	long key[2]={208,98};
	long key = 208930000000001;
	long *keyP=&key;
	char *dataP= (char *)malloc(sizeof(char));
	char *data = "dukl";
	dataP = data;
	

	obj_hash_table_t *hashtblp=obj_hashtable_create(sizeP,NULL,NULL,NULL,NULL);
	if(hashtblp){
		printf("\nyou have succeeded create your first hashtable!!!\n");
		printf("%d,%d,%s\n\n",hashtblp->name->mlen,hashtblp->name->slen,hashtblp->name->data);
        hashtable_rc_t state = obj_hashtable_insert(hashtblp,keyP,8,dataP);
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

    hashtable_rc_t isExist = obj_hashtable_is_key_exists(hashtblp,keyP,8);
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
	obj_hashtable_get(hashtblp,keyP,8,dataRev);
	printf("%s\n\n",dataRev[0]);

    obj_hash_node_t * node;
	hash_size_t       hash;
    hash = hashtblp->hashfunc(keyP,key_sizeP) % hashtblp->size;
	node = hashtblp->nodes[hash];
	while(node){
	  printf("%s\n",node->data);
	  node = node->next;
	}
/* 下面使用guti作为key,esm_ctx作为data的hashtable demo  */
	printf("\n\ntest_of_guti\n\n");
	guti_t *GutiTest;
	esm_context_t *EsmCtxTest;

    GutiTest = (guti_t *)malloc(sizeof(guti_t));
	EsmCtxTest = (esm_context_t *)malloc(sizeof(esm_context_t));

    printf("sizeof(guti_t)=%d\n",sizeof(guti_t));
    printf("sizeof(esm_context_t)=%d\n\n",sizeof(esm_context_t));

    (*GutiTest).m_tmsi = 2;
	(*GutiTest).gummei.plmn.mcc_digit3 = 2;
	(*GutiTest).gummei.plmn.mcc_digit2 = 0;
	(*GutiTest).gummei.plmn.mcc_digit1 = 8;
	(*GutiTest).gummei.plmn.mnc_digit3 = 0;
	(*GutiTest).gummei.plmn.mnc_digit2 = 9;
	(*GutiTest).gummei.plmn.mnc_digit1 = 3;
	(*GutiTest).gummei.mme_gid = 10;
    (*GutiTest).gummei.mme_code = 10;

	(*EsmCtxTest).n_active_ebrs = 1;
	(*EsmCtxTest).n_active_pdns = 1;
	(*EsmCtxTest).n_pdns = 2;
	(*EsmCtxTest).is_emergency = false;
//(*EsmCtxTest).esm_proc_data->...
    (*EsmCtxTest).T3489.id = 12;
	(*EsmCtxTest).T3489.sec = 11100;

    obj_hash_table_t *guti_htbl=obj_hashtable_create(10,NULL,NULL,NULL,NULL);
	if(guti_htbl){
	   printf("hashtable has been created successfully with guti as key,esm_ctx as data!!\n\n");
       hashtable_rc_t htblState = obj_hashtable_insert(guti_htbl,GutiTest,sizeof(guti_t),EsmCtxTest);
       if(htblState == HASH_TABLE_OK){
	      printf("insert successsfully!!\n");
	   }else
		 printf("wrong!!\n");
	}

    hashtable_rc_t isGutiExist = obj_hashtable_is_key_exists(guti_htbl,GutiTest,sizeof(guti_t));
	switch(isGutiExist){
		case HASH_TABLE_BAD_PARAMETER_HASHTABLE:
			printf("HASH_TABLE_BAD_PARAMETER_HASHTABLE\n\n");break;
		case HASH_TABLE_BAD_PARAMETER_KEY:
			printf("HASH_BAD_PARANETER_KEY\n\n");break;
		case HASH_TABLE_OK:
			printf("HASH_TABLE_OK\n\n");break;
		case HASH_TABLE_KEY_NOT_EXISTS:
			printf("HASH_TABLE_KEY_NOT_EXISTS\n\n");break;
	}

	guti_t *GutiTest2;
	GutiTest2 = (guti_t *)malloc(sizeof(guti_t));

    (*GutiTest2).m_tmsi = 2;
	(*GutiTest2).gummei.plmn.mcc_digit3 = 2;
	(*GutiTest2).gummei.plmn.mcc_digit2 = 0;
	(*GutiTest2).gummei.plmn.mcc_digit1 = 8;
	(*GutiTest2).gummei.plmn.mnc_digit3 = 0;
	(*GutiTest2).gummei.plmn.mnc_digit2 = 9;
	(*GutiTest2).gummei.plmn.mnc_digit1 = 3;
	(*GutiTest2).gummei.mme_gid = 10;
    (*GutiTest2).gummei.mme_code = 10;


    hashtable_rc_t isGuti2Exist = obj_hashtable_is_key_exists(guti_htbl,GutiTest2,sizeof(guti_t));
	switch(isGuti2Exist){
		case HASH_TABLE_BAD_PARAMETER_HASHTABLE:
			printf("HASH_TABLE_BAD_PARAMETER_HASHTABLE\n\n");break;
		case HASH_TABLE_BAD_PARAMETER_KEY:
			printf("HASH_BAD_PARANETER_KEY\n\n");break;
		case HASH_TABLE_OK:
			printf("HASH_TABLE_OK\n\n");break;
		case HASH_TABLE_KEY_NOT_EXISTS:
			printf("HASH_TABLE_KEY_NOT_EXISTS\n\n");break;
	}

    esm_context_t *EsmCtxRecv[1];
	obj_hashtable_get(guti_htbl,GutiTest,sizeof(guti_t),EsmCtxRecv);
	printf("%d\n\n",(*EsmCtxRecv[0]).T3489.id);
	printf("%d\n\n",(*EsmCtxRecv[0]).T3489.sec);


    return 0;
}

