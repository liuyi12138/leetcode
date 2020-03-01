//暴力排序思想 超时
int compare(void** a, void** b){
    return (*(int**)a)[0]*10 + (*(int**)a)[1] - (*(int**)b)[0]*10 - (*(int**)b)[1];
}

int maxEvents(int** events, int eventsSize, int* eventsColSize){
    qsort(events, eventsSize, sizeof(int*), compare);
    // for(int i = 0; i < eventsSize; ++i)
    //     printf("%d%d ",events[i][0],events[i][1]);
    // printf("\n");
    int count = 0;
    for(int i = 0; i < eventsSize; ++i){
        if(events[i][0] <= events[i][1]){
            int temp = events[i][0] + 1;
            count++;
            for(int j = i; j < eventsSize; ++j){
                if(events[j][0] > events[i][0])
                    break;
                events[j][0] = temp;
            }
            qsort(events+i+1, eventsSize-i-1, sizeof(int*), compare);     
        }
        // for(int i = 0; i < eventsSize; ++i)
        //     printf("%d%d ",events[i][0],events[i][1]);
        // printf("\n");   
    }
    return count;
}

//贪心思想 先参加最早结束的会议
int compare(void** a, void** b){
    return (*(int**)a)[1]*10 + (*(int**)a)[0] - (*(int**)b)[1]*10 - (*(int**)a)[0];
}

int maxEvents(int** events, int eventsSize, int* eventsColSize){
    qsort(events, eventsSize, sizeof(int*), compare);
    // for(int i = 0; i < eventsSize; ++i)
    //     printf("%d%d ",events[i][0],events[i][1]);
    bool day[1000000];
    memset(day, 0, 1000000*sizeof(bool));
    int count = 0;
    for(int i = 0; i < eventsSize; ++i){
        for(int j = events[i][0]; j <= events[i][1]; ++j){
            if(!day[j]){
                day[j] = true;
                count++;
                break;
            }
        }
    }
    return count;
}

