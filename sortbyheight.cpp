std::vector<int> sortByHeight(std::vector<int> a) {
    int temp;
    
    for (int i = 0; i < a.size(); i++){
        for (int j = i+1; j < a.size(); j++){
            if(a[i] > -1 && a[j] > -1){
                  if(a[i] > a[j]){
                      temp = a[i];
                      a[i] = a[j];
                      a[j] = temp;
                  }
            }
        }
    }   
    return a;
}
