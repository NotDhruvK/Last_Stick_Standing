#include "include_file.cpp"
#include "Player.hpp"
#include "data_and_related_functions.cpp"
using namespace std;

int switcher(int a_num)
{
  if(a_num == 1)
    return 2;
  else if(a_num == 2)
    return 1;
}

int main()
{
  bool quit{false};
  bool name_switcher {true};
  cout << "\t\t\t\t\tWelcome to the Line Strike game.";
  print_rules();
  do
  {
    the_beginning:

    string player1name{}, player2name{};
    cout << endl << endl << "Please enter Player 1's name: ";
    cin >> player1name;
    cout << "Please enter Player 2's name: ";
    cin >> player2name;
    Player player1(player1name);
    Player player2(player2name);
    unsigned short int name_switch_tracker{1};

    do
    {
      string curr_name{};
      if(name_switch_tracker == 1)
        curr_name = player1.get_name();
      else if(name_switch_tracker == 2)
        curr_name = player2.get_name();

      print_data(data);
      cout << "This is the current state of the board." << endl << endl;
      int position{}, lines_to_strike{};
      cout << curr_name << "'s turn." << endl;
      do
      {
        cout << "Where would you like to start cutting? : ";
        cin >> position;
        if(position > 15)
        {
          cout << "Invalid position" << endl;
        }
      } while(position > 15);

      cout << "Please enter the total number of lines to cut: ";
      cin >> lines_to_strike;
      change_data(data, position, lines_to_strike);
      int checker{};
      checker = check_data(data);
      if(checker == 1)
      {
        cout << curr_name << " has won!" << endl;
        char retry{}, same_name{};
        cout << "Would you like to play again? (y/n): ";
        cin >> retry;
        if(retry == 'y')
        {
          cout << "Continue with the same names? (y/n): ";
          cin >> same_name;
          if(same_name == 'y')
            reset_vector(data);
          else if(same_name == 'n')
            {
              reset_vector(data);
              goto the_beginning;
            }
        }
        else
        {
          cout << "Goodbye." << endl;
          quit = true;
        }
      }
      name_switch_tracker = switcher(name_switch_tracker);

    } while(quit == false);
  } while(quit == false);

}
