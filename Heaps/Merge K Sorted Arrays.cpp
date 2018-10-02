/*
	G4G HEAPS
    Given K sorted arrays of size K arranged in a form of a matrix, your task is to merge them.
    The output will be the sorted merged array.
*/


// Space Complexity O(K) & Time Complexity O(n*log(k))
int ans[1000003];
int j;

int *mergeKArrays(int arr[][N], int k)
{
    priority_queue <pair <int, pair<int, int> >, vector <pair <int, pair<int, int> > >, greater <pair <int, pair<int, int> > > > pq;
    for (int i = 0; i < k; i++) {
        pq.push(make_pair(arr[i][0], make_pair(i, 0)));
    }

    j = 0;
    for (int i = 0; i < k*k; i++) {
        ans[j++] = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        // debug
        cout << ans[j-1] << " " << row << " " << col << endl;
        pq.pop();
        
        if (col < k-1) {
            pq.push(make_pair(arr[row][col+1], make_pair(row, col+1)));
        }
        else {
            pq.push(make_pair(INT_MAX, make_pair(row, col+1)));
        }
    }
    
    return ans;
}