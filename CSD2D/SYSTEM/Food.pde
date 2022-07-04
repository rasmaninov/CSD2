class Food {
  PVector foodPosition = new PVector(0,0);
  float foodAmount = 0;
  float shade; //color of food
  float d; //collisionDetection distance
  boolean growth = true; //state of food(growing/notgrowing)

   //create food
  Food(float x, float y){
    foodPosition.set(x, y);
  }

  //checking if entity touches food or not
  boolean collisionDetection(float xA, float yA, float xB, float yB, float r2){
    d = dist(xA, yA, xB, yB);
    if(d <= foodAmount/5+r2){
      hit = true;
    } else {
      hit = false;
    }
    return hit;


  }

  //how big is the foodstack
  float foodAmount(){
    return foodAmount;
  }

  //update the food state and position
  void update(boolean hit, float player){
    if(hit){
      growth = false; // if it gets touched, it starts decaying
      if(foodAmount > 0){
        foodAmount -= 1;
        if(player == 1){ //depending on the player, if hit, then player gets life
          health1 = ent1.life(1);
        } else {
          health2 = ent2.life(1);
        }
      } else if(foodAmount <= 0){ //if food depletes, reseed on random coordinate with random amount
        foodPosition.set(random(width), random(height));
        foodAmount = -random(200);
        growth = true;

      }

    } else {
      if(growth){ //if food is growing , it grows
        foodAmount += 0.05;

      } else { //if not growing, it shrinks
        foodAmount -= 0.05;
        if(foodAmount <= 0){
          foodPosition.set(random(width), random(height));
          foodAmount = -random(200);
          growth = true;        }
      }
    }
    if(foodAmount >= 255){ //if maxamount of food reached, stop growing
    growth = false;
    }
  }

  PVector display(){ //displays the food, color is based on the amount of food
    if(foodAmount >= 255){
      shade = 255;
    } else {
      shade = foodAmount;
    }
    strokeWeight(0);
    stroke(20);
    fill(shade, shade, 0 , shade * 2);

    ellipse(foodPosition.x, foodPosition.y, foodAmount/5, foodAmount/5); //draw it
    return foodPosition;
  }


}
