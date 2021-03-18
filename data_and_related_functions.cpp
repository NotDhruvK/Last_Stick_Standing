using namespace std;

vector<vector<char>> data
  {
    {'|'},
    {'|',' ','|'},
    {'|',' ','|',' ','|'},
    {'|',' ','|',' ','|',' ','|'},
    {'|',' ','|',' ','|',' ','|',' ','|'},
    {},{},{},{},

  };

void print_data(vector<vector<char>> &vector) // prints the whole game board with the positions
{
    for(int i{0}; i < 5; ++i)
    {
      if(i == 0)
        {
          cout << "\t\t\t" << vector.at(0).at(0) <<"\t\t\t1" << endl;
        }
      if(i == 1)
        {
          cout << "\t\t       " << vector.at(1).at(0) << vector.at(1).at(1) <<
          vector.at(1).at(2) << "\t\t       2 3" << endl ;
        }
      if(i == 2)
      {
        cout << "\t\t      ";
        int size = vector.size();
        for(int j{}; j < size - 4; ++j)
        {
          cout << vector.at(i).at(j);
          if(j == size - 5)
          {
            cout << "\t\t      4 5 6";
            cout << endl;
          }
        }
      }
      if(i == 3)
      {
        cout << "\t\t     ";
        int size = vector.size();
        for(int j{}; j < size - 2; ++j)
        {
          cout << vector.at(i).at(j);
          if(j == size - 3)
          {
            cout << "\t\t     7 8 9 10";
            cout << endl;
          }
        }
      }


      if(i == 4)
      {
        cout << "\t\t    ";
        int size = vector.size();
        for(int j{}; j < size; ++j)
        {
          cout << vector.at(i).at(j);
          if(j == size - 1)
          {
            cout << "\t\t  11 12 13 14 15";
            cout << endl;
          }
        }

      }

  }
}


int check_data(vector<vector<char>> &vect)  // Will check the complete vector for a single standing line
{
  //will check if data has only one reamaining line
  cout << endl;
  vector<char> checker {};
  int size = vect.size();
  for(int i {}; i < size; ++i)
  {
    int size2 = vect[i].size();
    for(int j{}; j < size2; ++j)
    {
      char temp = vect.at(i).at(j);
      checker.push_back(temp);
    }
  };
  char temp{};
  unsigned short int total_line_count{};
  for(int i{}; i < 25; ++i)
    {
      temp = checker.at(i);
      if(temp == '|')
      {
        total_line_count += 1;
      }
    }

  if(total_line_count == 1)
    return 1;
  else
    return 2;
}


void change_data(vector<vector<char>> &vect, int position, int lines_to_strike)
{
  // will start at an element and strike the total no of lines to it's right
  unsigned short int first_start{}, second_start{};

  while(position < 16) // Determine the start position for outside vector (first variable).
  {
    if(position == 1)
    {
      first_start = 0;
      break;
    }
    else if(position == 2 || position == 3)
    {
      first_start = 1;
      break;
    }
    else if(position == 4 || position == 5 || position == 6)
    {
      first_start = 2;
      break;
    }
    else if(position == 7 || position == 8 || position == 9 || position == 10)
    {
      first_start = 3;
      break;
    }
    else if(position == 11 || position == 12 || position == 13 || position == 14 || position == 15)
    {
      first_start = 4;
      break;
    }
    else
    {
      cout << endl <<"Invalid position. Please choose from the given numbers: ";
      cin >> position;
      continue;
    }
  }

  while(position < 16) // Determine the start position for inside vector.
  {
    if(position == 1 || position == 2 || position == 4 || position == 7 || position == 11)
    {
      second_start = 0;
      break;
    }
    else if(position == 3 || position == 5 || position == 8 || position == 12)
    {
      second_start = 2;
      break;
    }
    else if(position == 6 || position == 9 || position == 13)
    {
      second_start = 4;
      break;
    }
    else if(position == 10 || position == 14)
    {
      second_start = 6;
      break;
    }
    else if(position == 15)
    {
      second_start = 8;
      break;
    }
    else
    {
      cout << endl << "Invalid position. Please choose from the given numbers: ";
      cin >> position;
      continue;
    }
  }

  {
    if(position == 1 && lines_to_strike > 1)
      {
        cout << "Can not strike more than 1 line. Please enter the correct number of lines to strike: ";
        cin >> lines_to_strike;
      }
    else if((2 <= position >= 3) && lines_to_strike > 2)
    {
      cout << "Can not strike more than 2 line. Please enter the correct number of lines to strike: ";
      cin >> lines_to_strike;
    }
    else if((4 <= position >= 6) && lines_to_strike > 3)
    {
      cout << "Can not strike more than 3 line. Please enter the correct number of lines to strike: ";
      cin >> lines_to_strike;
    }
    else if((7 <= position >= 10) && lines_to_strike > 4)
    {
      cout << "Can not strike more than 4 line. Please enter the correct number of lines to strike: ";
      cin >> lines_to_strike;
    }
    else if((11 <= position >= 15) && lines_to_strike > 5)
    {
      cout << "Can not strike more than 5 line. Please enter the correct number of lines to strike: ";
      cin >> lines_to_strike;
    }
  } // This scope just determines if the lines to cut are valid.

  unsigned short int loop_counter{};
  {
    if(lines_to_strike == 1)
      loop_counter = 1;
    else if(lines_to_strike == 2)
      loop_counter = 3;
    else if(lines_to_strike == 3)
      loop_counter = 5;
    else if(lines_to_strike == 4)
      loop_counter = 7;
    else if(lines_to_strike == 5)
      loop_counter = 9;
  } // This block sets the loop counter variable.

  //cout << first_start << "\t" << second_start << "\t" << loop_counter << endl;
  for(int i{second_start}, j{}; j < loop_counter; ++i, ++j)
  {
    char temp = vect.at(first_start).at(i);
    if(temp == '|')
      vect.at(first_start).at(i) = '+';
    else if (temp == ' ')
      vect.at(first_start).at(i) = '-';
  }

}

void reset_vector(vector<vector<char>> &vect)
{
  int vect_size = vect.size();
  for(int i{}; i < vect_size; ++i)
  {
    int vect_size2 = vect[i].size();
    for(int j{}; j < vect_size2; ++j)
    {
      char temp = vect.at(i).at(j);
      if(temp == '+')
      {
        vect.at(i).at(j) = '|';
      }
      else if(temp == '-')
      {
        vect.at(i).at(j) = ' ';
      }
    }
  }
}

void print_rules()
{
  cout << "\n\nRULES\n1. If you don't enter a correct number of lines to cut, you lose your chance as a penalty" << endl;
  cout << "2. You can't cut over already cut lines" << endl;
  cout << "3. Vertical as well as diagonal cuts are not allowed." << endl;
  cout << "4. The total number of lines to cut includes the line you start cutting from." << endl;

}
