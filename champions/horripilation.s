.name "horripilation"
.comment "Creepy crawlies warrior at yours disposal"

###ATTACK
###SQUAD TO COME FORWARD
	ld	%1,			r2

	st		r1, :bull

suite:	sti r1,%:live,%1
		st	r2, 500
		st	r1, 499
		st	r3, 498

live:	live %999

bull:
		st r1, r1
