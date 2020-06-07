# About

plan for HW3 in Algorithm 201 lecture



## Question?


- Although Minotaur can move horizontally,If that move doesn't make get close to me, then

  Minotaur doesn't choose moving horizontally?


- I constructed class Puzzle to store Map informations, move methods and so on.

  But how to input huge Map datas in preprocess?  

  ***possible solution***
  
  - symbolize one number to represent position state

    ex) 1011 = 11 => only right open , 1010 = 10 => right,bottom open

    Use bitmap operation to find specific position is open ( and(&) operation )


- how to make backtracking of my moves not to dive in infinite loop?


## Move Pattern of Minotaur

***each move checks*** 

- whether that move makes get close to me
 
- whether possible to make that move

If following 2 conditions hold, then Minotaur can make that move


Here's simple move logic of Minotaur
  
1) If moving horizontally makes get close to me, then move horizontally

   If it can't move horizontally(blocked by wall) or not making close to me, then goto next option


2) If moving vertically makes get close to me, then move vertically

   If it can't move vertically(blcoked by wall) or not making close to me, then goto next option


3) Neither option 1) nor 2), then Minotaur doesn't move( just skip its turn)


