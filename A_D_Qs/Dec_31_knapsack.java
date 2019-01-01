public class Item {
	int weight;
	int value;
}

public int knapsack(Item[] items, int W) {
	return knapsack(items, W, 0);
}

// naive brute force 
private int knapsack(Item[] items, int W, int i) {
	if (i == items.length) return 0;
	// if the item is too big to fill the space, skip it
	if (W - items[i].weight < 0)
		return knapsack(items, W, i+1);
	// Find the max of including or excluding the current item
	return Math.max(knapsack(items, W - items[i], i+1) + items[i].value, knapsack(items, W, i+1))
}



// DP approach
// weights = {1, 2, 3}
// values = {6, 10, 12}
//
// Values in the cell 
// = max possible value for that max weight given that items including first i items 

// 			max_weight(weight_limit) is    '0' '1' '2' '3' '4' '5'
// 						  					0	1	2	3	4	5
//only first 0 items can be included    0  [0   0   0   0   0   0] // we're including 0 items
//only first 1 items can be included    1  [0   6   6   6   6   6] // we can include values[0] 
//only first 2 items can be included    2  // either include second item(values[1]) or not include it // if we don't include the item, look above  [i-1][j]
//only first 3 items can be included3	3

//   	   	 0	 1	 2	 3	 4	 5
//       0  [0   0   0   0   0   0]
//       1  [0   6   6   6   6   6]  
//       2  [0   6  10]  // if we choose 'only' the second item to be included, 
//       				 // but we need to subtract the weight of that item (in the previous row cuz don't want to include the same item second time)
//       				 // Math.max (cache[i-1][j] <- previous item; '6' in this case
//       				 			  cache[i-1][j-weights[i-1]] + vals[i-1] <- cache[0][2-weights[0]] = '0' + '10');
//

//O (n * W)
public int knapsack(int W, int[] weights, int[] vals) {
	int [][] cache = new int [weight.length+1][W+1];

	for (int i = 1; i <= weight.length; i++) {
		for (int j = 1; j <= W; j++) {
			if (weights[i-1] > j)
				cache[i][j] = cache[i-1][j];
			else 
				cache[i][j] = Math.max(cache[i-1][j],
									   cache[i-1][j-weights[i-1]+vals[i-1]]);
		}
	}
}

	
