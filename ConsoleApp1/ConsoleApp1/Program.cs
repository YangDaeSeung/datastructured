using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NCS.CShap
{
    class Item
    {
        public enum eItemKind { Weapon, Armor, Acc, Etc }

        public Item(eItemKind eItemkind, string name, string comment, Status sStatus, int nGold)
        {
            m_eItemKind = eItemkind;
            m_strName = name;
            m_strComment = comment;
            m_sFunc = sStatus;
            m_nGold = nGold;
        }

        eItemKind m_eItemKind;
        string m_strName;
        string m_strComment;
        Status m_sFunc;
        int m_nGold;

        public eItemKind ItemKind //Setter,Getter
        {
            get { return m_eItemKind; }
            set { m_eItemKind = value; }
        }
        public string Name //Setter,Getter
        {
            get { return m_strName; }
            set { m_strName = value; }
        }
        public string Comment //Setter,Getter
        {
            get { return m_strComment; }
            set { m_strComment = value; }
        }
        public Status Function
        {
            get { return m_sFunc; }
            set { m_sFunc = value; }
        }
        public int Gold
        {
            get { return m_nGold; }
            set { m_nGold = value; }
        }
    }
    //c#에서 구조체는 정적할당된다.
    struct Status  //플레이어의 증가능력치를 구조체로 만들어 사용한다.
    {
        public int m_nHP, m_nMaxHP;
        public int m_nMP, m_nMaxMP;
        public int m_nStr;
        public int m_nDef;
        public int m_nInt;

        public Status(int nStr = 0, int nDef = 0, int nInt = 0, int nHP = 0, int nMaxHP = 0, int nMP = 0, int nMaxMP = 0)
        {
            m_nHP = nHP;
            m_nMaxHP = nMaxHP;
            m_nMP = nMP;
            m_nMaxMP = nMaxMP;
            m_nStr = nStr;
            m_nDef = nDef;
            m_nInt = nInt;
        }
        public static Status operator +(Status a, Status b)
        {
            return new Status(a.m_nHP + b.m_nHP, a.m_nMaxHP + b.m_nMaxHP,
                                    a.m_nMP + b.m_nMP, a.m_nMaxMP + b.m_nMaxMP,
                                    a.m_nStr + b.m_nStr, a.m_nDef + b.m_nDef, a.m_nInt + b.m_nInt);
        }
        public static Status operator -(Status a, Status b)
        {
            return new Status(a.m_nHP - b.m_nHP, a.m_nMaxHP - b.m_nMaxHP,
                                    a.m_nMP - b.m_nMP, a.m_nMaxMP - b.m_nMaxMP,
                                    a.m_nStr - b.m_nStr, a.m_nDef - b.m_nDef, a.m_nInt - b.m_nInt);
        }
    }

    class Player
    {
        //스텟
        Status m_cStatus;
        //이름
        string m_strName;
        int m_nLv;
        int m_nExp;

        int m_nGold; //소지금

        List<Item> m_listIventory = new List<Item>(); //인벤토리.
        List<Item> m_listEqument = new List<Item>(); //장비함.
        public enum eEqumentKind { Weapon, Armor, Acc }

        public Player(string name, int nHP, int nMP, int nStr, int nInt, int nDef)
        {
            m_cStatus = new Status(nStr, nDef, nInt, nHP, nHP, nMP, nMP);
            m_strName = name;
        }

        public void Attack(Player cTarget)
        {
            cTarget.m_cStatus.m_nHP = cTarget.m_cStatus.m_nHP - m_cStatus.m_nStr;
        }

        public bool Dead()
        {
            if (m_cStatus.m_nHP <= 0)
            {
                return true;
            }
            return false;
        }

        public void StillItem(Player cTarget)
        {
            SetInvetory(cTarget.GetInvetory(0));
            m_nExp += cTarget.m_nExp;
        }

        public void Recovery()
        {
            m_cStatus.m_nHP = m_cStatus.m_nMaxHP;
            m_cStatus.m_nMP = m_cStatus.m_nMaxMP;
        }

        public void SetInvetory(Item item)
        {
            m_listIventory.Add(item);
        }

        public Item GetInvetory(int idx)
        {
            return m_listIventory[idx];
        }

        public void DeleteInventory(Item item)
        {
            m_listIventory.Remove(item);
        }

        public void SetEquemnt(Item item) //아이템장착
        {
            //장비아이템일때만 해당 아이템을 셋팅한다.
            if (item.ItemKind < Item.eItemKind.Etc)
            {
                ReleaseEquemnt((eEqumentKind)item.ItemKind);
                //장비할아이템을 장착하고, 능력치를 증가시킨다.
                m_listEqument[(int)eEqumentKind.Weapon] = item;
                m_cStatus += item.Function;

                DeleteInventory(item);
            }
        }
        public void ReleaseEquemnt(eEqumentKind eEqument)
        {
            Item cEqumentItem = m_listEqument[(int)eEqument];

            if (cEqumentItem != null)
            {
                SetInvetory(cEqumentItem);
                m_cStatus -= cEqumentItem.Function;
            }
        } //아이템해제

        public void Show()
        {
            Console.WriteLine(String.Format("######## {0} ########", m_strName));
            Console.WriteLine(String.Format("HP:{0}/{1}", m_cStatus.m_nHP, m_cStatus.m_nMaxHP));
            Console.WriteLine(String.Format("MP:{0}/{1}", m_cStatus.m_nMP, m_cStatus.m_nMaxMP));
            Console.WriteLine(String.Format("Str/Int/Def:{0}/{1}/{2}", m_cStatus.m_nStr, m_cStatus.m_nInt, m_cStatus.m_nDef));
            Console.WriteLine(String.Format("Lv:{0}", m_nLv));
            Console.WriteLine(String.Format("Exp:{0}", m_nExp));
            Console.WriteLine(String.Format("Gold:{0}", m_nGold));
        }

        public void ShowInevtory()
        {
            Console.WriteLine(String.Format("######## Equment ########", m_strName));
            for (int i = 0; i < m_listEqument.Count; i++)
            {
                Console.WriteLine(String.Format("{0}:{1}", (eEqumentKind)i, m_listEqument[i]));
            }
            Console.WriteLine(String.Format("######## Invetory ########", m_strName));
            for (int i = 0; i < m_listIventory.Count; i++)
            {
                Console.WriteLine(String.Format("{0}:{1}", i, m_listIventory[i].Name));
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Player cPlayer = new Player("Player", 100, 100, 10, 10, 10);
            Player cMonster = new Player("Slime", 100, 100, 10, 0, 0);

            Status sStatus = new Status(100);
            Item cWeapon = new Item(Item.eItemKind.Weapon, "목검", "데미지증가", sStatus, 100);

            cMonster.SetInvetory(cWeapon);

            while (true)
            {
                Console.WriteLine("###################################");
                if (!cPlayer.Dead())
                    cPlayer.Attack(cMonster);
                else
                {
                    Console.WriteLine("GameOver");
                    break;
                }
                cMonster.Show();
                if (!cMonster.Dead())
                    cMonster.Attack(cPlayer);
                else
                {
                    Console.WriteLine(String.Format("몬스터가 쓰러뜨렸습니다!"));
                    cPlayer.StillItem(cMonster);
                    cPlayer.ShowInevtory();
                    break;
                }
                cPlayer.Show();
                Console.WriteLine("###################################");
            }
        }
    }
}