class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, 1e9));
        for(int i =0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            matrix[u][v] = wt;
            matrix[v][u] = wt;
        }
        for(int i =0; i < n; i++) matrix[i][i] = 0;

	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < n; j++) {
	            if(matrix[i][j] == -1) matrix[i][j] = 1e9;
	            if(i == j) matrix[i][j] = 0;
	        }
	    }
	    
	    for(int via = 0; via < n; via++) {
	        for(int i = 0; i < n; i++) {
	            for(int j = 0; j < n; j++) {
    	           matrix[i][j] = min(matrix[i][j], matrix[i][via]+matrix[via][j]);
    	        }
    	    }
	    }
	    
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < n; j++) {
	            if(matrix[i][j] == 1e9) matrix[i][j] = -1;
	        }
	    }

        int minCity = INT_MAX, ansCity = -1;
        for(int i = 0; i < n; i++) {
            int cityCount = 0;
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] <= distanceThreshold) {
                    cityCount++;
                }
            }
            if(cityCount <= minCity) {
                minCity = cityCount;
                ansCity = i;
            }
        }

        return ansCity;
    }
};