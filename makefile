objects = hashtable_demo.o obj_hashtable.o  bstrlib.o dynamic_memory_check.o backtrace.o
OPENAIR_DIR =-I ~/openair5g-cn/src/
INCLUDE = -I./ ${OPENAIR_DIR}utils ${OPENAIR_DIR}utils/hashtable ${OPENAIR_DIR}utils/bstr ${OPENAIR_DIR}common ${OPENAIR_DIR}common/itti ${OPENAIR_DIR}nas/esm ${OPENAIR_DIR}nas/util ${OPENAIR_DIR}nas ${OPENAIR_DIR}nas/api/mme ${OPENAIR_DIR}common/3gpp_24.008.h ${OPENAIR_DIR}nas/ies

ACHIEVE = ~/openair5g-cn/src/utils/dynamic_memory_check.c 
ACHIEVE2 = ~/openair5g-cn/src/utils/bstr/bstrlib.c
ACHIEVE3 = ~/openair5g-cn/src/common/itti/backtrace.c
hashtableDemo:${objects}
	gcc -o hashtableDemo ${objects}
hashtable_demo.o:hashtable_demo.c 
	gcc -c hashtable_demo.c ${INCLUDE}
obj_hashtable.o:obj_hashtable.c 
	gcc -c obj_hashtable.c  ${INCLUDE}
dynamic_memory_check.o:${ACIEVE}
	gcc -c ${ACHIEVE} ${INCLUDE}
bstrlib.o:${ACHIEVE2}
	gcc -c ${ACHIEVE2} ${INCLUDE}
backtrace.o:${ACHIEVE3}
	gcc -c ${ACHIEVE3} ${INCLUDE}
clean:
	rm hashtableDemo ${objects}
