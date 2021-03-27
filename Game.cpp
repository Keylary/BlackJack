#include "Game.h" //!-> include h
using namespace std;


// Конструктор этого класса принимает ссылку на вектор строк, представляющих
// имена игроков - людей. Конструктор создает объект класса Player для каждого имени
Game::Game(const vector<string>& names)
{
    // создает вектор игроков из вектора с именами
    vector<string>::const_iterator pName;
    //for (pName = names.begin(); pName != names.end(); ++pName)
    //!!!!!!! Home work
    for (const string name : names)
    {
        m_players.push_back(Player(name));
    }

    // запускает генератор случайных чисел
    m_deck.populate();
    m_deck.shuffle();
}


Game::~Game()
{}

void Game::play()
{
    const int startCardCount = 2;
    // раздает каждому по две стартовые карты
    vector<Player>::iterator pPlayer;
    for (int i = 0; i < startCardCount; ++i)
    {
        //for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        //!!!!!!! Home work
        for (Player &pPlayer : m_players)
        {
            m_deck.deal(pPlayer);
        }
        m_deck.deal(m_house);
    }

    // прячет первую карту дилера
    m_house.flipFirstCard();

    // открывает руки всех игроков
    //for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    //!!!!!!! Home work
    for (Player& pPlayer : m_players)
    {
        cout << pPlayer << endl;
    }
    cout << m_house << endl;

    // раздает игрокам дополнительные карты
    // for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    //!!!!!!! Home work
    for (Player& pPlayer : m_players)
    {
        m_deck.additionalCards(pPlayer);
    }

    // показывает первую карту дилера
    m_house.flipFirstCard();
    cout << endl << m_house;

    // раздает дилеру дополнительные карты
    m_deck.additionalCards(m_house);

    if (m_house.isBusted())
    {
        // все, кто остался в игре, побеждают
        // for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
        //!!!!!!! Home work
        for (Player& pPlayer : m_players)
        {
            if (!(pPlayer.isBusted()))
            {
                pPlayer.win();
            }
        }
    }
    else
    {
        // сравнивает суммы очков всех оставшихся игроков с суммой очков дилера
        //for (pPlayer = m_players.begin(); pPlayer != m_players.end();
         //   ++pPlayer)
        //!!!!!!! Home work
        for (Player& pPlayer : m_players)
        {
            if (!(pPlayer.isBusted()))
            {
                if (pPlayer.getTotal() > m_house.getTotal())
                {
                    pPlayer.win();
                }
                else if (pPlayer.getTotal() < m_house.getTotal())
                {
                    pPlayer.lose();
                }
                else
                {
                    pPlayer.push();
                }
            }
        }

    }

    // очищает руки всех игроков
    // for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    //!!!!!!! Home work
    for (Player &pPlayer : m_players)
    {
        pPlayer.clear();
    }
    m_house.clear();
}
