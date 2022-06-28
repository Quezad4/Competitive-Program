bool belmanFord(){
	for(int i = 0; i<N-1; i++){
		for(int u = 0; u<N; u++){
			for(auto j : adjList[u]){
				if(dist[u] + j.second < dist[j.first]){
					dist[j.first] = dist[u] + j.second;
				}
			}
		}
	}
	for(int u = 0; u<N; u++){
		for(auto j : adjList[u]){
			if(dist[u] + j.second < dist[j.first]){
				return false;
			}
		}
	}
	return true;
}
