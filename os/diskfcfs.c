 #include<stdio.h>
 #include<stdlib.h>
 void main()
 {
 int n,i,seek=0,diff;
 printf("Enter the size of the Queue: ");
 scanf("%d",&n);
 int queue[n+1];
 printf("Enter the queue: ");
 for(i=1;i<=n;i++)
 scanf("%d",&queue[i]);
 printf("Enter the initial head position: ");
 scanf("%d",&queue[0]);
 printf("Movement of cylinders,\n");
 for(i=0;i<n;i++)
 {
 diff=abs(queue[i+1]-queue[i]);
 seek+=diff;
 printf("%d ->",queue[i]);
 }
 printf("%d",queue[n]);
 printf("\nTotal seek time = %d\n",seek);
 printf("Avg seek time = %f\n",(float)seek/n);
 }