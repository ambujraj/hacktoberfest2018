import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Set;

public class Graph {
	private class Vertex {
		String name;
		HashMap<Vertex, Integer> neighbors;

		Vertex(String name) {
			this.name = name;
			this.neighbors = new HashMap<>();
		}

		public boolean equals(Object other) {
			Vertex ov = (Vertex) other;
			return this.name.equals(ov.name);
		}

		public int hashCode() {
			return this.name.hashCode();
		}
		public void display() {
			String rv = "";
			rv = rv + this.name + "=>";
			Set<Vertex> nbrs = this.neighbors.keySet();
			for (Vertex nbr : nbrs) {
				rv = rv + nbr.name + "(" + this.neighbors.get(nbr) + "),";
			}
			rv = rv + "END";
			System.out.println(rv);
		}
	}

	private HashMap<String, Vertex> vertices;

	Graph() {
		this.vertices = new HashMap<>();
	}

	public int numVertices() {
		return this.vertices.size();
	}

	public void addVertex(String name) {
		if (this.vertices.containsKey(name)) {
			return;
		}

		Vertex vtx = new Vertex(name);
		this.vertices.put(name, vtx);
	}

	public void removeVertex(String name) {
		if (!this.vertices.containsKey(name)) {
			return;
		}

		Vertex vtx = this.vertices.get(name);
		Set<Vertex> nbrs = vtx.neighbors.keySet();
		for (Vertex nbr : nbrs) {
			nbr.neighbors.remove(vtx);
		}

		this.vertices.remove(name);

	}

	public int numEdges() {
		int rv = 0;
		Collection<Vertex> vtces = this.vertices.values();
		for (Vertex vtx : vtces) {
			rv = rv + vtx.neighbors.size();
		}
		rv = rv / 2;
		return rv;
	}

	public void addEdge(String v1, String v2, int weight) {
		Vertex vtx1 = this.vertices.get(v1);
		Vertex vtx2 = this.vertices.get(v2);

		if (vtx1 == null || vtx2 == null || vtx1.neighbors.containsKey(vtx2)) {
			return;
		}

		vtx1.neighbors.put(vtx2, weight);
		vtx2.neighbors.put(vtx1, weight);
	}

	public void removeEdge(String v1, String v2) {
		Vertex vtx1 = this.vertices.get(v1);
		Vertex vtx2 = this.vertices.get(v2);

		if (vtx1 == null || vtx2 == null || !vtx1.neighbors.containsKey(vtx2)) {
			return;
		}

		vtx1.neighbors.remove(vtx2);
		vtx2.neighbors.remove(vtx1);
	}

	public void display() {
		Set<String> vtces = this.vertices.keySet();
		for (String vtxname : vtces) {
			Vertex vtx = this.vertices.get(vtxname);
			vtx.display();
		}
		System.out.println("***************************************");
	}

	public boolean hasPath(String v1, String v2) {
		Vertex vtx1 = this.vertices.get(v1);
		Vertex vtx2 = this.vertices.get(v2);

		if (vtx1 == null || vtx2 == null) {
			return false;
		}
		HashMap<Vertex, Boolean> explored = new HashMap<>();
		return DFSI(vtx1, vtx2, explored);

	}
}
