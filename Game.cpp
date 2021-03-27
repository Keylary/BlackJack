#include "Game.h" //!-> include h
using namespace std;


// ����������� ����� ������ ��������� ������ �� ������ �����, ��������������
// ����� ������� - �����. ����������� ������� ������ ������ Player ��� ������� �����
Game::Game(const vector<string>& names)
{
    // ������� ������ ������� �� ������� � �������
    vector<string>::const_iterator pName;
    //for (pName = names.begin(); pName != names.end(); ++pName)
    //!!!!!!! Home work
    for (const string name : names)
    {
        m_players.push_back(Player(name));
    }

    // ��������� ��������� ��������� �����
    m_deck.populate();
    m_deck.shuffle();
}


Game::~Game()
{}

void Game::play()
{
    const int startCardCount = 2;
    // ������� ������� �� ��� ��������� �����
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

    // ������ ������ ����� ������
    m_house.flipFirstCard();

    // ��������� ���� ���� �������
    //for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    //!!!!!!! Home work
    for (Player& pPlayer : m_players)
    {
        cout << pPlayer << endl;
    }
    cout << m_house << endl;

    // ������� ������� �������������� �����
    // for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    //!!!!!!! Home work
    for (Player& pPlayer : m_players)
    {
        m_deck.additionalCards(pPlayer);
    }

    // ���������� ������ ����� ������
    m_house.flipFirstCard();
    cout << endl << m_house;

    // ������� ������ �������������� �����
    m_deck.additionalCards(m_house);

    if (m_house.isBusted())
    {
        // ���, ��� ������� � ����, ���������
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
        // ���������� ����� ����� ���� ���������� ������� � ������ ����� ������
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

    // ������� ���� ���� �������
    // for (pPlayer = m_players.begin(); pPlayer != m_players.end(); ++pPlayer)
    //!!!!!!! Home work
    for (Player &pPlayer : m_players)
    {
        pPlayer.clear();
    }
    m_house.clear();
}
