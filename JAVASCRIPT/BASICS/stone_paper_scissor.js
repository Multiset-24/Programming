let n=prompt("Enter the number of rounds you want to play");
let playerScore=0;
let computerScore=0;

let user = prompt("Enter your choice: stone, paper or scissor");

for(let i=0;i<n;i++){
    let choices = ["stone", "paper", "scissor"];
    let randomIndex = Math.floor(Math.random()*3);
    let computer = choices[randomIndex];
    console.log("Computer's choice: "+computer);
    if(user==computer){
        console.log("It's a tie");
    }
    else if(user=="stone" && computer=="scissor" || user=="paper" && computer=="stone" || user=="scissor" && computer=="paper"){
        console.log("You win");
        playerScore++;
    }
    else if(user!="stone" && user!="paper" && user!="scissor"){
        console.log("Invalid choice");
        i--;
    }
    else{
        console.log("Computer wins");
        computerScore++;
    }
    if(i!=n-1)user = prompt("Enter your choice: stone, paper or scissor");
}

if(playerScore>computerScore){
    console.log("You win the game and your score is "+playerScore);
}
else if(playerScore<computerScore){
    console.log("Computer wins the game");
}