import os
import json

def generate_tree_data(root_dir):
    tree_data = []
    def natural_sort_key(s):
        import re
        return [int(text) if text.isdigit() else text.lower() for text in re.split(r'(\d+)', s['id'])]
    def add_nodes(path, parent_node):
        items = os.listdir(path)
        # 根据id（basename）进行排序
        #items.sort(key=lambda x: os.path.basename(x))
        # 按照自然排序（数值顺序）对items进行排序
        items.sort(key=lambda x: natural_sort_key({'id': os.path.basename(x)}))
        
        for item in items:
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
