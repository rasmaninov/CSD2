#include <iostream>

class Ui {
public:
  Ui();
  ~Ui();
  static bool validateSelection(std::string selection, std::string selectionOptions[],
      int numOptions);
  static std::string retrieveUserInput(std::string selectionOptions[], int numOptions);

  static std::string retrieveUserSelection(std::string selectionOptions[], int numOptions);

  static float retrieveValueInRange(float min, float max);
};
