package main

import (
	"fmt"
	"math"
	"math/rand"
)

type Solution struct {
	radius, xCenter, yCenter float64
}

func Constructor(radius float64, x_center float64, y_center float64) Solution {
	return Solution{
		radius:  radius,
		xCenter: x_center,
		yCenter: y_center,
	}
}

func (s *Solution) RandPoint() []float64 {
	for {
		x := rand.Float64()*2 - 1
		y := rand.Float64()*2 - 1
		if x*x+y*y < 1 {
			return []float64{s.xCenter + x*s.radius, s.yCenter + y*s.radius}
		}
	}
}

func (s *Solution) RandPoint1() []float64 {
	r := math.Sqrt(rand.Float64())
	sin, cos := math.Sincos(rand.Float64() * 2 * math.Pi)
	return []float64{s.xCenter + r*cos*s.radius, s.yCenter + r*sin*s.radius}
}

func main() {
	cls := Constructor(1.0, 0.0, 0.0)
	fmt.Println(cls.RandPoint())
	fmt.Println(cls.RandPoint())
	fmt.Println(cls.RandPoint())

	fmt.Println(cls.RandPoint1())
	fmt.Println(cls.RandPoint1())
	fmt.Println(cls.RandPoint1())
}
