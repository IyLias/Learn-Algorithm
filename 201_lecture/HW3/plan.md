# About

plan for HW3 in Algorithm 201 lecture



## Question?


- Although Minotaur can move horizontally,If that move doesn't make get close to me, then

  Minotaur doesn't choose moving horizontally?

  



## Move Pattern of Minotaur

  
1) If moving horizontally makes get close to me, then move horizontally

   If it can't move horizontally(blocked by wall) or not making close to me, then goto next option


2) If moving vertically makes get close to me, then move vertically

   If it can't move vertically(blcoked by wall) or not making close to me, then goto next option


3) Neither option 1) nor 2), then Minotaur doesn't move( just skip its turn)


