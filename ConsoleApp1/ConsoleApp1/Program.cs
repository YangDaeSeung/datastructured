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
        public int m_nHP;
        public int m_nMP;
        public int m_nStr;
        public int m_nDef;
        public int m_nInt;

        public Status(int nStr = 0, int nDef = 0, int nInt = 0, int nHP = 0, int nMP = 0)
        {
            m_nHP = nHP;
            m_nMP = nMP;
            m_nStr = nStr;
            m_nDef = nDef;
            m_nInt = nInt;
        }
        public void AddStatus(int var)
        {
            m_nHP += var;
            m_nMP += var;
            m_nStr += var;
            m_nInt += var;
            m_nDef += var;
        }
        public static Status operator +(Status a, Status b)
        {
            return new Status(a.m_nHP + b.m_nHP, a.m_nMP + b.m_nMP,
                                    a.m_nStr + b.m_nStr, a.m_nDef + b.m_nDef, a.m_nInt + b.m_nInt);
        }
        public static Status operator -(Status a, Status b)
        {
            return new Status(a.m_nHP - b.m_nHP, a.m_nMP - b.m_nMP,
                                    a.m_nStr - b.m_nStr, a.m_nDef - b.m_nDef, a.m_nInt - b.m_nInt);
        }
    }

    class ItemManager //아이템매니저: 아이템을 보관해놓고 가져다쓰는 물류센터
    {
        public enum eItem { WoodSword, BoneSword, WoodArmor, BoneArmor, WoodRing, BoneRing, HPPotion, MPPotion, Stone, Boom, MAX };
        List<Item> m_listItemList;

        public ItemManager()
        {
            m_listItemList = new List<Item>((int)eItem.MAX);
            m_listItemList.Add(new Item(Item.eItemKind.Weapon, "목검", "데미지증가", new Status(100), 100));
            m_listItemList.Add(new Item(Item.eItemKind.Weapon, "본소드", "데미지증가", new Status(200), 200));
            m_listItemList.Add(new Item(Item.eItemKind.Weapon, "나무갑옷", "방어력증가", new Status(0, 100), 100));
            m_listItemList.Add(new Item(Item.eItemKind.Weapon, "본아머", "방어력증가", new Status(0, 200), 200));
            m_listItemList.Add(new Item(Item.eItemKind.Weapon, "나무반지", "체력증가", new Status(0, 0, 0, 100), 100));
            m_listItemList.Add(new Item(Item.eItemKind.Weapon, "해골반지", "체력증가", new Status(0, 0, 0, 200), 200));
            m_listItemList.Add(new Item(Item.eItemKind.Weapon, "힐링포션", "HP회복", new Status(0, 0, 0, 100), 100));
            m_listItemList.Add(new Item(Item.eItemKind.Weapon, "마나포션", "MP회복", new Status(0, 0, 0, 0, 100), 100));
            m_listItemList.Add(new Item(Item.eItemKind.Weapon, "짱돌", "단일개체데미지", new Status(100), 100));
            m_listItemList.Add(new Item(Item.eItemKind.Weapon, "폭탄", "다수개체데미지", new Status(200), 200));
        }

        public Item GetItem(eItem idx)
        {
            return m_listItemList[(int)idx];
        }
    }

    class Player
    {
        //스텟
        Status m_cStatus;

        public int m_nMaxHP;
        public int m_nMaxMP;
        //이름
        string m_strName;
        int m_nLv;
        int m_nExp;

        int m_nGold; //소지금

        List<Item> m_listIventory = new List<Item>(); //인벤토리.
        List<Item> m_listEqument = new List<Item>((int)eEqumentKind.MAX); //장비함.
        public enum eEqumentKind { Weapon, Armor, Acc, MAX }

        public Player(string name, int nHP = 100, int nMP = 100, int nStr = 10, int nInt = 10, int nDef = 10, int nExp = 10, int nGold = 0)
        {
            m_cStatus = new Status(nStr, nDef, nInt, nHP, nMP);
            m_nMaxHP = nHP;
            m_nMaxMP = nMP;
            m_strName = name;
            m_nExp = nExp;
            m_nGold = nGold;
            m_nLv = 1;
            m_listEqument = new List<Item>((int)eEqumentKind.MAX); //장비함.
            for (int i = 0; i < (int)eEqumentKind.MAX; i++)
                m_listEqument.Add(null);
        }
        public void Attack(Player cTarget)
        {
            cTarget.m_cStatus.m_nHP = cTarget.m_cStatus.m_nHP - (m_cStatus.m_nStr - cTarget.m_cStatus.m_nDef);
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
            m_cStatus.m_nHP = m_nMaxHP;
            m_cStatus.m_nMP = m_nMaxMP;
        }

        public bool LvUp(int var = 10, int maxexp = 100)
        {
            if (m_nExp > maxexp)
            {
                m_cStatus.AddStatus(var);
                m_nExp -= maxexp;
                m_nMaxHP += var;
                m_nMaxMP += var;
                return true;
            }

            return false;
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

        public bool Buy(int nIventoryIdx, Player cTarget)
        {
            Item cItem = cTarget.GetInvetory(nIventoryIdx);

            if (cItem.Gold <= m_nGold)
            {
                SetInvetory(cItem);
                m_nGold -= cItem.Gold;
                return true;
            }

            return false;
        }
        public void Sell(int nIventoryIdx)
        {
            Item cItem = GetInvetory(nIventoryIdx);
            DeleteInventory(cItem);
            m_nGold += cItem.Gold;
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
            Console.WriteLine(String.Format("HP:{0}/{1}", m_cStatus.m_nHP, m_nMaxHP));
            Console.WriteLine(String.Format("MP:{0}/{1}", m_cStatus.m_nMP, m_nMaxMP));
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
                if (m_listEqument[i] != null)
                    Console.WriteLine(String.Format("{0}:{1}", (eEqumentKind)i, m_listEqument[i].Name));
                else
                    Console.WriteLine(String.Format("{0}:{1}", (eEqumentKind)i, "null"));
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
        enum eStage
        {
            CREATE,
            TOWN,
            INVENTORY,
            STORE,
            FILED, //필드선택
            BATTLE, //전투지역
            GAMEOVER,
            THEEND
        }
        enum eMonster { SLIME, SKELTON, BOSS, MAX };

        static eStage m_eStage = eStage.CREATE;


        static bool Battle(Player cPlayer, Player cMonster)
        {
            Console.WriteLine("####################");
            if (!cPlayer.Dead())
                cPlayer.Attack(cMonster);
            else
            {
                m_eStage = eStage.GAMEOVER;
                return true;
            }
            cMonster.Show();
            if (!cMonster.Dead())
                cMonster.Attack(cPlayer);
            else
            {
                Console.WriteLine(String.Format("몬스터가 쓰러뜨렸습니다!"));
                cPlayer.StillItem(cMonster);
                cPlayer.ShowInevtory();
                if (cPlayer.LvUp())
                {
                    Console.WriteLine("LvUp!");
                    cPlayer.Show();
                    m_eStage = eStage.TOWN;
                    return true;
                }
            }
            cPlayer.Show();
            Console.WriteLine("###################################");
            return false;
        }
       static void SwapStatus(Status a,Status b)
        {
            Status temp = a;
            a = b;
            b = temp;
        }
        static void Main(string[] args)
        {

            Status sA, sB;
            sA = new Status(100);
            sB = new Status(0, 100);

            Console.WriteLine(String.Format("A:{0},{1]", sA.m_nStr, sA.m_nDef));
            Console.WriteLine(String.Format("B:{0},{1]", sB.m_nStr, sB.m_nDef));
            SwapStatus(sA, sB);
            Console.WriteLine(String.Format("{0},{1]", sA.m_nStr, sA.m_nDef));
            Console.WriteLine(String.Format("{0},{1]", sB.m_nStr, sB.m_nDef));

            ItemManager cItemManager = new ItemManager();
            Player cPlayer = null;
            Player cMonster = null;
            Player cStore = new Player("Store");


            

            cStore.SetInvetory(cItemManager.GetItem(ItemManager.eItem.HPPotion));
            cStore.SetInvetory(cItemManager.GetItem(ItemManager.eItem.MPPotion));
            cStore.SetInvetory(cItemManager.GetItem(ItemManager.eItem.Stone));
            cStore.SetInvetory(cItemManager.GetItem(ItemManager.eItem.Boom));

            eMonster nMonsterIdx = eMonster.SLIME;
            int nSelect;
            while (m_eStage != eStage.GAMEOVER)
            {
                switch (m_eStage)
                {
                    case eStage.CREATE:
                        Console.WriteLine("케릭터이름을 입력하세요:");
                        string strName = Console.ReadLine();
                        cPlayer = new Player(strName, 100, 100, 10, 10, 10, 0, 9999999);
                        m_eStage = eStage.TOWN;
                        break;
                    case eStage.INVENTORY:
                        cPlayer.ShowInevtory();
                        Console.WriteLine("어떻게 하시겠습니까? 1:장착, 2:해재 etc:마을");
                        nSelect = int.Parse(Console.ReadLine());
                        if (nSelect == 1)
                        {
                            nSelect = int.Parse(Console.ReadLine());
                            Item cItem = cPlayer.GetInvetory(nSelect);
                            cPlayer.SetEquemnt(cItem);
                        }
                        else if (nSelect == 2)
                        {
                            nSelect = int.Parse(Console.ReadLine());
                            Item cItem = cPlayer.GetInvetory(nSelect);
                            for (int i = 0; i < (int)Player.eEqumentKind.MAX; i++)
                                Console.Write(String.Format("{0}:{1},", i, (Player.eEqumentKind)i));
                            cPlayer.ReleaseEquemnt((Player.eEqumentKind)nSelect);
                        }
                        else
                        {
                            m_eStage = eStage.TOWN;
                        }
                        break;
                    case eStage.STORE:
                        Console.WriteLine("어떻게 하시겠습니까? 1:구매, 2:판매 etc:마을");
                        nSelect = int.Parse(Console.ReadLine());
                        if (nSelect == 1)
                        {
                            cStore.ShowInevtory();
                            nSelect = int.Parse(Console.ReadLine());
                            cPlayer.Buy(nSelect, cStore);
                        }
                        else if (nSelect == 2)
                        {
                            cPlayer.ShowInevtory();
                            nSelect = int.Parse(Console.ReadLine());
                            cPlayer.Sell(nSelect);
                        }
                        else
                        {
                            m_eStage = eStage.TOWN;
                        }
                        break;
                    case eStage.TOWN:
                        cPlayer.Recovery();
                        cPlayer.ShowInevtory();
                        Console.Write("마을 입니다. 어디로 가시겠습니까? ");
                        for (int i = (int)eStage.TOWN + 1; i < (int)eStage.GAMEOVER; i++)
                            Console.Write(String.Format("{0}:{1},", i, (eStage)i));
                        m_eStage = (eStage)int.Parse(Console.ReadLine());
                        break;
                    case eStage.FILED:
                        Console.Write("필드을 선택하세요! ");
                        for (int i = (int)eMonster.SLIME; i < (int)eMonster.MAX; i++)
                            Console.Write(String.Format("{0}:{1},", i, (eMonster)i));
                        nMonsterIdx = (eMonster)int.Parse(Console.ReadLine());

                        switch (nMonsterIdx)
                        {
                            case eMonster.SLIME:
                                cMonster = new Player("Slime", 100, 100, 10, 0, 0, 100);
                                cMonster.SetInvetory(cItemManager.GetItem(ItemManager.eItem.WoodSword));
                                cMonster.SetInvetory(cItemManager.GetItem(ItemManager.eItem.WoodArmor));
                                cMonster.SetInvetory(cItemManager.GetItem(ItemManager.eItem.WoodRing));
                                break;
                            case eMonster.SKELTON:
                                cMonster = new Player("Skelton", 200, 200, 20, 10, 0, 100);
                                cMonster.SetInvetory(cItemManager.GetItem(ItemManager.eItem.BoneSword));
                                cMonster.SetInvetory(cItemManager.GetItem(ItemManager.eItem.BoneArmor));
                                cMonster.SetInvetory(cItemManager.GetItem(ItemManager.eItem.BoneRing));
                                break;
                            case eMonster.BOSS:
                                cMonster = new Player("Boss", 300, 300, 30, 15, 0, 100);
                                break;
                            default:
                                m_eStage = eStage.FILED;
                                break;

                        }

                        m_eStage = eStage.BATTLE;
                        break;
                    case eStage.BATTLE:
                        Battle(cPlayer, cMonster);
                        break;
                    case eStage.GAMEOVER:
                        Console.WriteLine("GAMEOVER");
                        break;
                    case eStage.THEEND:
                        Console.WriteLine("THE END");
                        break;
                    default:
                        break;
                }
            }
        }
    }
}