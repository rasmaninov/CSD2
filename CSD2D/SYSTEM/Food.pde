class Food {
  PVector foodPosition = new PVector(0,0);


  Food(float x, float y){
    // float x = random(400);
    // float y = random(400);
    foodPosition.set(x, y);
  }

  void update(){

  }

  PVector display(){
    fill(255,255,0,100);

    ellipse(foodPosition.x, foodPosition.y, 50, 50);
    return foodPosition;
  }


}
