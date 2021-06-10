import java.util.*;


public class IX {
	public static void main(String... args) {
		int n = 7;
		ArrayList<Vertex> graph = createHasseGraph(n);
		System.out.println("DFS: ");
		dfs(graph.get(0));
		System.out.println("BFS: ");
		for (Vertex u: graph) {
			u.visited = false;
		}
		bfs(graph.get(0));
	}
	
	public static void dfs(Vertex u) {
		System.out.println(
			"id: " + u.nodeId + "; partition: " + Arrays.toString(u.partition)
		);
		u.visited = true;
		for (Vertex v: u.adjacents) {
			if (!v.visited) {
				dfs(v);
			}
		}
	}
	
    public static void bfs(Vertex u) {
		LinkedList<Vertex> queue = new LinkedList<>();
		u.visited = true;
		queue.add(u);
		while (queue.size() != 0) {
			u = (Vertex) queue.remove();
			System.out.println(
				"id: " + u.nodeId + "; partition: " + Arrays.toString(u.partition)
			);
			for (Vertex v: u.adjacents) {
				if (!v.visited) {
                    v.visited = true;
                    queue.add(v);
				}
			}
		}
	}
	
	public static ArrayList<Vertex> createHasseGraph(int n) {
		int id = 1;
		int[] partition = new int[]{n};
		Vertex start = new Vertex(id, partition);
		LinkedList<Vertex> queue = new LinkedList<>();
		HashMap<String, Vertex> map = new HashMap<>();
		queue.add(start);
		map.put(Arrays.toString(partition), start);
		ArrayList<Vertex> graph = new ArrayList<>();
		while (queue.size() != 0) {
			Vertex u = (Vertex) queue.remove();
			graph.add(u); 
			for (int i = 0; i < u.partition.length; i++) {
				for (int j = 1; j <= u.partition[i] / 2; j++) {
					partition = new int[u.partition.length + 1];
					for (int k = 0; k < i; k++) {
						partition[k] = u.partition[k];
					}
					partition[i] = j; 
					partition[i + 1] = u.partition[i] - j; 
					for (int k = i + 2; k < partition.length; k++) {
						partition[k] = u.partition[k - 1];
					}
					Arrays.sort(partition);
					for (int k = 0; k < partition.length / 2; k++) {
						int t = partition[k];
						partition[k] = partition[partition.length - k - 1];
						partition[partition.length - k - 1] = t;
					}
					String key = Arrays.toString(partition);
					//System.out.println(key);
					Vertex v = map.get(key);
					if (v == null) {
						v = new Vertex(++id, partition);
						queue.add(v);
						map.put(key, v);	
					}
					u.adjacents.add(v);
					v.adjacents.add(u);
				}
			}
		}
		return graph;
	}
	
}

class Vertex {
	int nodeId = 0;
	int[] partition = null; 
	ArrayList<Vertex> adjacents = new ArrayList<>();
	boolean visited = false;
	
	Vertex(int nodeId, int[] partition) {
		this.nodeId = nodeId;
		this.partition = partition;
	}
}