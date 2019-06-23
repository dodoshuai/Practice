.global _start
.equ NUM 6
.equ V 5
_start:
	mov r3,#V	//r3=5;
	mov	r1,#NUM	//r1=6;
		
AAA:			//
	mov	r2,r1	//r2=r1;
	mov r0,#NUM	//r0=6;
BBB:			//循环自身 6*6==6+6+6+6+6+6 
	add	r1,r2	//r1=r1+r2;
	subs r0,#1	//r0=r0-1;更新条件码 
//	cmp r0,#0
	bne	BBB		//不为零就继续循环 
CCC:
	subs r3,#1	//r3=r3-1;更新条件码 
	bne	AAA		// 不为零就继续循环
				//r1里存储最后的结果 
.end
	
			
