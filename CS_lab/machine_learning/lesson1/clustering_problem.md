# clustering_problem
## Group high dims points into clusters
- by cosine dist(as vector)
- by jaccard dist(as sets)
- by Euclidean dist(as points)

### Methods
- Agglomerative(botom to up)
- Divisive(top to down)

### How to combine two nearest clusters
- How represent a acluster or more
- how determin the "nearness"
- when stop combine

 1. use Euclidean dist: Each cluster has a  **centroid** = average of points
 2. Measure by dist of centroid
 3. 
 

 ## K-means clustering
 > start by picking k , picking one point per cluster 
1. For each point , place it in the cluster whose current centroid its nearest
2. After all points are assigned , update the loc of centroids of the k clusters
3. Reassign all points to their closest centroid 
4. repeat 2 & 3 until convergence

## BFR algorithm
