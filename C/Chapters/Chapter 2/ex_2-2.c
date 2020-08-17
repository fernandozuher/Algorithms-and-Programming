// Write a loop equivalent to the for loop above without using
// && or ||.

//for (i=O; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
	//s[i] = c;

for (i=O; i<lim-1; ++i)
	if ((c = getchar()) != '\n')
		if(c != EOF)
			s[i] = c;
		else
			break;
	else
		break;