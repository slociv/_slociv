import os
import json

def generate_tree_data(root_dir):
    tree_data = []

    def add_nodes(path, parent_node):
        for item in os.listdir(path):
            item_path = os.path.join(path, item)
            if os.path.isdir(item_path):
                node = {
                    "id": os.path.basename(item_path),
                    "text": os.path.basename(item_path),
                    "state": "closed",
                    "children": []
                }
                parent_node.append(node)
                add_nodes(item_path, node["children"])
            else:
                node = {
                    "id": os.path.basename(item_path),
                    "text": os.path.basename(item_path),
                    "state": "open",
                    "attributes": {
                        "url": item_path.replace("\\", "/")  # Convert backslashes to slashes for URLs
                    }
                }
                parent_node.append(node)

    add_nodes(root_dir, tree_data)
    return tree_data

if __name__ == "__main__":
    root_directory = "notes"  # The root directory containing your notes
    tree_data = generate_tree_data(root_directory)
    
    # Save tree_data.json at the same level as index.html
    with open("tree_data.json", "w", encoding="utf-8") as f:
        json.dump(tree_data, f, ensure_ascii=False, indent=4)
    print("tree_data.json generated successfully.")
