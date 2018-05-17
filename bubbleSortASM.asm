;*****************************************************************
; AUTHOR     : Jason Inciong & Jesse Mazzella
; ASSIGNMENT : MASM5
; CLASS      : CS3B
; SECTION    : T/Th 3:30pm
; DUE DATE   : 5/17/18
;*****************************************************************
;*****************************************************************
; BubbleSort (Assembly)
; ________________________________________________________________
; This program compares the time between a C++ implemented bubble
; sort versus an assembly bubble sort.
;*****************************************************************/
.586
.model flat,C
bubbleSortASM PROTO,
	pArray:PTR DWORD, Count:DWORD	

.code

bubbleSortASM PROC USES eax ecx esi,

mov ecx,Count
dec ecx			 	        ; decrement count by 1

L1:	push ecx			     ; save outer loop count
	mov	esi,pArray	         ; point to first value

L2:	mov	eax,[esi]		     ; get array value
	cmp	[esi+4],eax        	 ; compare a pair of values
	jge	L3			         ; if [esi] <= [edi], don't exch
	xchg eax,[esi+4]	     ; exchange the pair
	mov	[esi],eax

L3:	add	esi,4		         ; move both pointers forward
	loop	L2			     ; inner loop

pop	ecx			    	     ; retrieve outer loop count
loop L1			        	 ; else repeat outer loop

ret

bubbleSortASM ENDP

END