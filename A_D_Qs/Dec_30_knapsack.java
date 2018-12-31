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
