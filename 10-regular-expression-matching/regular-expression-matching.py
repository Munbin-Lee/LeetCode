class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        def rep(x):
            if x.group(1) == "*": return "\**"
            return x.group(0)
        
        p = re.sub("(.)(\*)", rep, p)
        return re.fullmatch(p, s)