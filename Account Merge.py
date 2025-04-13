class Solution:
    def accountsMerge(self, accounts):
        from collections import defaultdict

        parent = {}
        email_to_name = {}

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            parent[find(x)] = find(y)

        for account in accounts:
            name = account[0]
            for email in account[1:]:
                if email not in parent:
                    parent[email] = email
                email_to_name[email] = name
                union(account[1], email)

        unions = defaultdict(list)
        for email in parent:
            root = find(email)
            unions[root].append(email)

        result = []
        for root, emails in unions.items():
            result.append([email_to_name[root]] + sorted(emails))
        return result
