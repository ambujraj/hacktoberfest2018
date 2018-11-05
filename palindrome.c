/*
	
	Palindrome number in C using remainder (%)
	@author - bhansa
	@createdon - 09/07/2017

*/

#include<stdio.h>

int main(){

	int number, num, revnumber = 0, rem;

	scanf("%d", &number);

	//save it 
	num = number;

	//reverse the number
	while(num != 0){
		// understand the process here
		/*
			Okay, Let's suppose num or number = 121
			It goes on till the num is not zero(0)
				loop1 :
					 rem = 121%10 -> 1
					 revnumber = 0*10 + 1 -> 1
					 num = 121/10 -> 12
				Loop2 :
					rem = 12%10 -> 2	(taking out the last corner integer)
					 revnumber = 1*10 + 2 -> 12
					 num = 12/10 -> 12 -> 1

				loop3 :
					predict it.

		*/
		rem = num%10;
		revnumber  = revnumber*10 + rem;
		num /= 10;
	
	}

	//now see if the original and this reversed number is same or not 
	if(number == revnumber){
		printf("%d is a palindrome.\n",n);
	}
	else
		printf("%d is not a palindrome.\n",n);

}

/* Example
 Input- 121
 Output - 121 is a palindrome number.
 Input - 122
 Output - 122 is not a palindrome number.
 */
