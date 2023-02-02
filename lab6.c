#include<stdio.h>

#define capacity 50

void main() {
    int timeLimit = 10;
    int bucketCapacity = 0, outputRate = 5;
    
    while(timeLimit < 100) {
        int newPacket;
        printf("\nenter new packet size: ");
        scanf("%d", &newPacket);
        
        if(newPacket < capacity) {
            bucketCapacity = bucketCapacity + newPacket;
            printf("\nbucket capacity currently: %d", bucketCapacity);
            bucketCapacity = bucketCapacity - outputRate;
            printf("\nbucket capacity after output: %d", bucketCapacity);
            timeLimit++;
        } else if(newPacket > capacity || (newPacket + bucketCapacity) > capacity) {
            printf("\nnew packet cannot be added to bucket");
            bucketCapacity = bucketCapacity - outputRate;
            printf("\nbucket capacity after output: %d", bucketCapacity);
            timeLimit++;
        } else if(bucketCapacity < 0) {
            bucketCapacity = 0;
            printf("\nbucket capacity after output: %d", bucketCapacity);
            timeLimit++;
        }
    }
}
