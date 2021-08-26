package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

const Bits8 = (1 << 9) - 1

type Codec struct {
}

func Constructor() Codec {
	return Codec{}
}

// Serializes a tree to a single string.
func (this *Codec) serialize(root *TreeNode) string {
	return string(this.dfs(root, nil))
}

func (this *Codec) dfs(root *TreeNode, data []byte) []byte {
	if root == nil {
		data = append(data, '0')
		return data
	}
	str := fmt.Sprintf("%x", root.Val)
	bs := []byte(str)
	data = append(data, byte(len(bs)))
	data = append(data, bs...)
	data = this.dfs(root.Left, data)
	data = this.dfs(root.Right, data)
	return data
}

// Deserializes your encoded data to tree.
func (this *Codec) deserialize(str string) *TreeNode {
	data := []byte(str)
	ret, _ := this.decode(data)
	return ret
}

func (this *Codec) decode(data []byte) (*TreeNode, []byte) {
	if len(data) == 0 {
		return nil, data
	}
	if data[0] == '0' {
		return nil, data[1:]
	}
	l := int(data[0])
	byts := data[1 : 1+l]
	v := int(0)
	fmt.Sscanf(string(byts), "%x", &v)
	head := &TreeNode{Val: v}
	head.Left, data = this.decode(data[1+l:])
	head.Right, data = this.decode(data)
	return head, data
}

func main() {
	root := &TreeNode{Val: 6666}
	root.Left = &TreeNode{Val: 7777}
	root.Right = &TreeNode{Val: 8888}
	root.Right.Left = &TreeNode{Val: 9999}
	root.Right.Right = &TreeNode{Val: 123123123}
	enc, dec := Constructor(), Constructor()
	str := enc.serialize(root)
	head := dec.deserialize(str)
	fmt.Println(head)
}
