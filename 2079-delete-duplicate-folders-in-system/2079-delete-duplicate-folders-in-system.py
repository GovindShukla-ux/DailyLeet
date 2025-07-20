class Solution(object):
    def deleteDuplicateFolder(self, paths):
        """
        :type paths: List[List[str]]
        :rtype: List[List[str]]
        """
        tree = {}
        for path in paths:
            curr = tree
            for name in path:
                curr = curr.setdefault(name, {})

        self.store = defaultdict(list)

        def encode(node):
            if not node:
                return "()"

            parts = []
            for key in sorted(node.keys()):
                sub_node = node[key]
                parts.append(key + encode(sub_node))

            signature_content = "".join(parts)
            full_signature = "(" + signature_content + ")"

            if signature_content:
                self.store[full_signature].append(node)
            
            return full_signature

        def remove(nodes):
            for item in nodes:
                item.clear()
                item["#"] = True

        encode(tree)

        for group in self.store.values():
            if len(group) > 1:
                remove(group)

        result = []
        def collect(node, path):
            for key, sub in list(node.items()):
                if key == "#":
                    continue
                if "#" in sub:
                    continue

                new_path = path + [key]
                result.append(new_path)
                collect(sub, new_path)
        
        collect(tree, [])
        return result