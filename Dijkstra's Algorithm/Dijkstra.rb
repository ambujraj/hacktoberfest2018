max=Float::INFINITY
nodes={'A'=>0, 'B'=>max, 'C'=>max, 'D'=>max, 'E'=>max,'F'=>max,'G'=>max, 'H'=>max}
edge_costs_hash={"AB"=>2, "AC"=>1,"AD"=>3,"BE"=>2,"CE"=>2,"CF"=>2,"DF"=>2, "EF"=>1, "EG"=>2, "EH"=>4, "FH"=>5}


def get_path_tree(edge_costs_hash)
    path_tree={}
    edge_costs_hash.each do |edge, cost|
        connected_nodes = edge.split('')
        if path_tree.key?(connected_nodes[0])
            path_tree[connected_nodes[0]].push({connected_nodes[1]=> cost})        
        else
            path_tree[connected_nodes[0]] = [{connected_nodes[1]=> cost}]
        end
    end
    return path_tree
end

def get_closest_child(children)
    children_with_closeness_order = children.sort_by {|child| child.values.first}
    return children_with_closeness_order.first
end

def should_update_node_value(nodes, child, parent)
    return nodes[child.keys.first] > nodes[parent] + child.values.first
end

def check_and_change_path(path, child, parent, children)
    end_points = path.map {|p| p.split('')[1]}
    if (end_points.index(child.keys.first))
        path[end_points.index(child.keys.first)] = parent.dup.concat(child.keys.first)
    else
        path.push(parent.dup.concat(child.keys.first))
    end 
end 

def get_matched_edge(path, to_match)
    matched_edge = path.select {|p| p.split('')[1] == to_match}.first
    return matched_edge
end 

def find_target_and_create_path(path, source, target, final_path = [])
    matched_edge = get_matched_edge(path, target)
    if (matched_edge.split('')[0] != source)
        target = matched_edge.split('')[0]
        find_target_and_create_path(path, source, target, final_path)
    end
    final_path.push(matched_edge)
    return final_path
end 

def find_shortest_path(edge_costs_hash, nodes, source, target)
    path = []
    path_tree = get_path_tree(edge_costs_hash)
    path_tree.each do |parent, children|
        children.each {|child|
            if (should_update_node_value(nodes, child, parent))
                nodes[child.keys.first] = nodes[parent] + child.values.first
                check_and_change_path(path, child, parent, children)   
            end 
        }
    end
    return find_target_and_create_path(path, source, target)
end

print("Path -> ", find_shortest_path(edge_costs_hash, nodes, 'A', 'H'))
