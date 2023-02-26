int solution(vector<int> arr, int src, int dest){
    map<int,int> visA,visB;
    int start = arr[src];
    int curr = 1;
    set<int> s; 
    
    
    for(auto &x: arr){
        s.insert(x);
    }
    
    while(visA[start] == 0){
        visA[start] = curr; 
        curr++;
        start = arr[start];
        if(start == -1){
            break; 
        }
    }
    start = arr[dest];
   
    while(visB[start] == 0){
        visB[start] = curr;
        curr++;
        start = arr[start];
        if(start == -1){
            break;
        }
    }
   
    vector<pair<int,int>> vp;
    for(auto &x: s){
        if(visA[x] != 0 && visB[x] != 0){ 
            pair<int,int> p = {visA[x] + visB[x], x};
            vp.push_back(p);
        }
    }
    
    sort(vp.begin(), vp.end());
    return vp[0].second;
}
