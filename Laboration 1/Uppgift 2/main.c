//
//  main.c
//  Uppgift 2
//
//  Created by Staffan Brickman on 2016-04-12.
//  Copyright © 2016 Mälardalens Högskola. All rights reserved.
//

#include <stdio.h>


int sum(int num){
    
    if(num<1){
        return 0;
    }
    if(num == 1){
        printf("%d = ",num);
        return 1;
    }
    printf("%d + ",num);
    int summa = num + sum(num-1);
    return summa;
    
}

int main() {
    int num;
    scanf(" %d",&num);
    int summa = sum(num);
    printf("%d\n",summa);
    return 0;
}
