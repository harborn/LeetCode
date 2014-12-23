
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;


// got problem. not use this code.
bool helper(vector<vector<char>> &board, vector<vector<bool>> &visited, string word, int r, int c) {
	if (word.empty()) return true;
	//if (word[index] != board[r][c]) return false;

	bool up = false, right = false, down = false, left = false;

	word.erase(word.begin());
	//up
	if (r > 0 && !visited[r - 1][c]) {
		visited[r - 1][c] = true;
		up = helper(board, visited, word, r - 1, c);
		if (up) return true;
	}
	//right
	if (c < board[0].size() - 1 && !visited[r][c + 1]) {
		visited[r][c + 1] = true;
		right = helper(board, visited, word, r, c + 1);
		if (right) return true;
	}
	//down
	if (r < board.size() - 1 && !visited[r + 1][c]) {
		visited[r + 1][c] = true;
		down = helper(board, visited, word, r + 1, c);
		if (down) return true;
	}
	//left
	if (c > 0 && !visited[r][c - 1]) {
		visited[r][c - 1] = true;
		left = helper(board, visited, word, r, c - 1);
		if (left) return true;
	}
	return false;
}

bool exist(vector<vector<char>> &board, string word) {
	if (word.empty()) return false;

	int row = board.size();
	int col = board[0].size();

	vector<vector<bool>> visited(row, vector<bool>(col, false));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == word[0]) {
				visited[i][j] = true;
				bool ret = helper(board, visited, word, i, j);
				if (ret) return true;
				visited[i][j] = false;
			}
		}
	}
	return false;
}

// exist2 works fine.
bool search(vector<vector<char> > &board,
	string& word,
	int* visited,
	int op, //0 up, 1 down, 2 left, 3 right  
	int matchLen,
	int i,
	int j)
{
	if (matchLen == word.size()) return true;
	int row = board.size();
	int col = board[0].size();
	if (i + 1 < row && op != 0) // up
	{
		if (visited[(i + 1)*col + j] == 0 &&
			board[i + 1][j] == word[matchLen])
		{
			visited[(i + 1)*col + j] = 1;
			if (search(board, word, visited, 1, matchLen + 1, i + 1, j))
				return true;
			visited[(i + 1)*col + j] = 0;
		}
	}
	if (i - 1 >= 0 && op != 1) // down
	{
		if (visited[(i - 1)*col + j] == 0 && board[i - 1][j] == word[matchLen])
		{
			visited[(i - 1)*col + j] = 1;
			if (search(board, word, visited, 0, matchLen + 1, i - 1, j))
				return true;
			visited[(i - 1)*col + j] = 0;
		}
	}
	if (j + 1 < col && op != 2) // left
	{
		if (visited[i*col + j + 1] == 0 && board[i][j + 1] == word[matchLen])
		{
			visited[i*col + j + 1] = 1;
			if (search(board, word, visited, 3, matchLen + 1, i, j + 1))
				return true;
			visited[i*col + j + 1] = 0;
		}
	}
	if (j - 1 >= 0 && op != 3) // right
	{
		if (visited[i*col + j - 1] == 0 && board[i][j - 1] == word[matchLen])
		{
			visited[i*col + j - 1] = 1;
			if (search(board, word, visited, 2, matchLen + 1, i, j - 1))
				return true;
			visited[i*col + j - 1] = 0;
		}
	}
	return false;
}

bool exist2(vector<vector<char> > &board, string word) {
	if (word.size() == 0) return false;
	if (board.size() == 0 || board[0].size() == 0) return false;
	int row = board.size();
	int col = board[0].size();
	int * visited = new int[row*col];
	memset(visited, 0, row*col*sizeof(int));
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j] == word[0])
			{
				visited[i*col + j] = 1;
				if (search(board, word, visited, -1, 1, i, j))
					return true;
				visited[i*col + j] = 0;
			}
		}
	}
	delete visited;
	return false;
}

double diffclock(clock_t clock1, clock_t clock2)
{
	double diffticks = clock1 - clock2;
	double diffms = (diffticks * 1000) / CLOCKS_PER_SEC;
	return diffms;
}


int main(void)
{
	string lines[] = { "elxllvxegzmvgnhrypvagxrgwktiqnyuavfnsfsbgewnrferubrcykjwveenrfhtamhvtzwafspzxvqtwkxwwgttkzgdenzhcgcvhyxosonrjgmhsjeo", "qxkcyqidehkipofwofmgtazfilocwuqotatstbvzkhhzvmxjrjrnlsutdixbdoqwqjolklkwstvpgsyzdropjikoriquygsqphcbuoxniucoodpruegg", "mrudzkzxsupjbrmxgjkofpetutnoztwmmrrndtmwncfqtsnbdaplrvglptbqpycdpwrspdqehyudsjevjwictpnkkpbznfdebwysbpwjnsmfcscnqnqk", "cdumuvojbtnepmxqdvbsopzskdfaqxkudhhxexhfqwkfkjxnezhuqgmamsbcrnxuwgsbdbgtxsaidxxiyfcplrpxlqccgzxchrdksmfpgfxkexudcysp", "phnaarfisckztqllcqckxcubzqebpyqgifjkwosqqeplucyysajreftfwzgnazvkgeufsovisnvpptnkwybagwgeyotypokwteblsywmlrbbnrljrmlx", "ltbjiujxjtvczwprvlfifhjsaubrjmpugsfqnopyjlcijrbgfgpkpacpvfhgtwczohrdxhbgudqfxroczdopdqeavliojkqarjdqshwomoujfinhnbws", "tatoobfxmxzfidwbkupwjlgqtvxgxvzqyuhmxollnltvqpyalowwbepvcmdzkeriaauyohjducbktzkhpjdrpsorhrstykbykxwbeigzmhlihwpwhupw", "pdoyxirvsuvfrsivcowqwiydgpbnmrlbwbbtkuqcomjfgrckgbaejzjrqkgcdrfctgxfcojqctvkkausbuymvhdmsjqxcwzxezchnmzrfxbrxvmapkmn", "srbmcrleplcukgdzscszbtraofafpmujdvxfnjmcwoygubhpgzojuhkkmkrexmnchlkuuwzqmxyibhxhioqcvcmindmmrbozoyvkwuciscrvlqcteuxa", "zlkmryyibmhqndcjzfutjnovdsokpomozyaqwyzxmipbnslnxhgguxbzpslegxsfxuytuztjhikvaxkzesgypjahdllllgticrexqxgzfqwiqghubpvq", "bxxeilsvtleveksuhatotswjygfzvasyxrficxdvijtmtniaodrhvnswtxvrappxhuhjtlhduarqnzsdfjmcxeyscwlcldbszjetwnwspoiepbiukuzj", "zxedtrfhuiburhpnulilbqqttypgsoptmvwhnbqhmuddbstygbjjtzcnzstsiknwgkgvnwczqgfuyysgbdqwfslemgyvrmtzwzujwyjoeqifoclrgdnl", "ybrkhqhycbzyatjysspyizfycrrkwhxuiofpeoogrpeujosdijbtjhtlalxwsutciarpohvgxcaisulcgovpvrcxezwyvpafprufzqlysngmkroqfkfd", "djchkyhfphkeafkbxxzrnfdxyrngdulgfnppowufdgkgnwhkvhbiogfpyuxdqkkvzbknygtdnfjadtnaaojqvqhvleydokzomldmsyrhfbhkuulwluoi", "mwfzcddtoejcpmojnfqsiafewqchmtrypwytcdmqhxuwmkizrytcaygxqlgceabvwboyedqnamlowtnoujqujytajacnafkyizxoepbgcnvygkoatgxf", "fqfqsjgsrqtzrsoxhpgjcbklnaljhkoobvetemovfjxwblwiccuffgssgddnqrbrmimtwcobllamywvbargfxyzdddttwwmjgbcddsgpegbeeyfernlo", "nlutqnomlbxsczvhubwakaeoakvsxgiltcejrswdvtxzvshpvdrhfvygftafbisvnyeeqcjoygntawkycbfhwdpeyplaadvnbbttgdhelxzmtjkxmrfk", "xwovozvocsdfwwzcbigphfbbqnacgfmdedbsewgjrjonhprlyzafediwsjyyqmeurfmwdufufvjnlcalbaqhfbdxkdxaqbxjgjfkgmglisavuagwcydh", "zjglmeoeflomwtycigosyqnvrvttvydvhjgupwyvhmjgijiqpykqpzliugdpegmmsvihriezvnhfwpxoqhefgrpcxstbzgptbxaugfvduckrujhkqlry", "cgcbyvczdusgttbbaweubqnvzufrfypjetkcrpcujwbcpeepakmddzycufubdlnhhzmyoqszmveezkvcwhfzheedjygnltwstiqjallngptizokxyrxh", "vbkhbswomujhfbqfmduvsndtenrceojcrvlsnjizdriitbofekcxafseujgbzrdsmqmzzvbcmjlfkbnpnponvgrrszsrqxkcnwcmtdrgoenbfaquqgin", "obegbxatumwkkawefpmvtzwaamvsudfjglrhirbffzpqbnwididyhazhowbjbguhslrcfujmtaewoaetkhtshsbwqdhrldzfqqixktkfuodkrhfboyvy", "tzwjcfdpicvyufwgyinsyqcpxjtnioldnjmropjwtexnjvvjdicbygtxsmlacydsirlyjuxcausjrnvuyzxyhqwzehbhhebrymqhhnljjdvatqwtptrw", "kpyqyzzggaxenpnwcyfneanzsjshdlgpbefzdhfjhfpuucszbamfcagvjycojkfmonmuurfbyvytxssysefvglqslugxfmjtbvpvpvypqwinpcohjtep", "huhuporucbpfyfapayfsxpfostvbpcqywysnomjspbxnizfkxmcwbhktdiwukpuinmwdahxpiufqtkaswepxmbtrjrntghettcywjvlurqmkapfytwyh", "xtyhklcruimqklmuixoaoamqprrlppsnitwsgalbjyrtldntadvqgijxbairpbgzwctccfdndwhozwjcafuipdfqdojurptptpryuxlztspvraztftbw", "xipawyxpqqgjhyhbxvcsprpguozbicyhlpjjngbfzhrghakgvmzlgotafvbpxbwiqfugovlneetmfdscstnyijapebebdamthibxdnkhrgvylobdhqdr", "zdgdhmhmmvfwdhtiwgpponozbrfkhkehommxzvjnqojvxfdvnvnbibclujxbubkiqzhpuqcngoievobijolrrnelxbptfzdvykkvaoigesmzgojpcwiw", "kohjqwcvyfqwpctrqbxxukwcyiscecaqrizjgdgekydbawssaqpwcoycwseavftopuxvydckbhmddgxfypbadacbsjdpqwdhrccrhgbknpntynywcczf", "ediymloeitlbwqsfwvqmlfhlshhujibnmjmavcffvsitiazhxptkuavnhfjtnlizuucpyhwuzenkgoredkoamkpvpyoejxeetgvspsoqydafsrjxdxxr", "jmnandfwclcytyskqgaqldvdwebaeatppiqcoxaqidqdbintqnjcqfhnliprlijatbehyezihqlkaydtnpxgwevjpmdawmcppgwpmyxwokgqkmjzdghz", "nckcqnenbgcqobfczeypohhavtcabjbomlsczwraewtszyxadxptgywdrydthehvqaaryrtdnmxoluoqsflaejevjhqroyoeaoxaiqdxdbmqxagrgtsm", "fyhofyfvywbamyaupguujgkgisaqlscsqmhxmovmkwmxvotmungdvsmekmwxgzqylxvxlsjwpxvmnoyiegnzybfinchtdxroupnihygyvbkirksxqizq", "jeaxiislfmbcdqkkoqjltvwkgqkyyjrkprjybbljpnlsfxfupqhildutweuwplgfepdgtqrkdedjbifsymalswfqdbmsmtxskcaftrqyvtjydoqddsox", "pvnuwzmkumdhqfmjxcisvrtaijdneukvrxpqydavrfcilorktbeqvxrdjwqnqciibxyzcawuiacvrvfkxjashtvsqnfgpnqqmqrorokbqmwhibrhmuzv", "nwndlumahesvvjmozwpqlnzvqrecndaabngmiuoryiptrbhtzylmlkjbdngqsgtttbhdvxxvfmpzpysozfdkrmovcunuciqxjzbgxaeemvdbtxruewhw", "lvtnrgjtrzqcztjytpehkikfhcamahilcbyvjkoajgdkcokvfpdpznugrusubcffdgcpqqpbzuobkyypnbgmrbvkvngzqogvujkmbcpaydblcacrdjgw", "kbjhqpiidpezyqnzudctgfgkhientkjfnupdmxorostmkgoflsasxgehqiumufrhainogbfuvyjfhzksrkmqsrxjztxuzodbxqpftwboxmuelgyetlxl", "cwwdqtzpkfsjxjorfrfeebkrkjwduvqyrpdhkdyuiqffzvyhnglrhwitfgwbbpzteccohblrtqzvoxcbdpsnlcgsjftmuuhazkoinbaiuzdiyfjcvdpi", "hxbscwfwtmwuyncnqewkfzuehfieizmswpkzorxheudejfszmomrpgvwmdawepobebassxbytgdeoxgansrcapboubnzsdazectzbvxxdabrzhrmblpc", "cqswtfxmjznpbgofdmchodyolsaodrqfhlddqbrbaetekhjovlxmqvadncsqukxdvbimezpgfikssvinifzzabeqewiahgfejosnpitxqgpibzymexng", "brwhqfhzlmdwcwjseerwkghofhalenrhgoowtvxgkbemxngdrzbehkuoruzyjrfrhuqcrnkdoosnbasuauahguwyqvwbodtvxjxrwhunvmaynvvprxwx", "ssviqtmexfawqzpojkbgyehnzccqzbpttnelgqqfxsenrtbaffjgjqtkuycvbrpuevgnlyukqyxjsamxfvdqlzahzccawrwcmepzcmjukiecjqcqnhhy", "ijfjojjkbgopmgrrsclclrhwhlowuvwdhdmvnyhqgvhsbyjtdxyoofmyqaukyrpfucchcjxiefaifmbijzyxgmvwnsjnjasfeupgfmojtprbdvlmwkjd", "whblbkaklsrpogwvvmfodyrgvdsspexnnyzolzawurnkylgtynjdnbklecdtiagvahjljjjfdxrbkzwkohoeiypocujlwsiwbsimdrriqljbkhnbpbfz", "buqgoztktbgvvohzibhymtzycnzrqetuajaoityeuhzqxirfjaexvfyyuzrnekhevhvecviwcjoarhhdklcftcfpczcillohujnwfxtjgjjzrrebejiz", "lornpvvahkjbvwyattmbcvdtohwvqfwevnrkjpmsbwtwsrzomlppiskzchwuosyjisvtjhlkdeiwyhkkubbdwmeyvaujuvucnpxywiiapqypakbuldzh", "rdfmfcxaxremickemsgbkeskouhcxijqorcttbvssceaeogsinwstofkkomjwxzkobgjcbbwdfyjvfcduyypofbztpipnicdlipqjqopynyvucbqcbht", "gjsbacqpmutacisoagfavfwrixhmyrfgczhcezsqulsyvkoxrtyozugjtpxtgdzkegnihfbdstcpeqmxmklngtwzltstytedbrnjyomskohohvnvgaio", "ueohziaacefdvsovjbnvrwlysyvaadoujedjnelriqwgkldtorqfnbgfzbfafwwqaazpgkiqcfwnsaigtzngavoaxvcerauucwjiiszlzxarzizuhobi", "krkhooniojctfndqfcdecdxdlyytnbdxungidtqrcumkiqcnufuwitcvuaqhbtgvimflhyflsrxahzqcgmaohcmbecihwqegckslixzcowfwwvacjatq", "fhujjcrhvvoxhglrfkutgzrewrjhuezzltkuydetbssiadcfnwawxscvllcfrbgcvtzvwdozxgizkmezigvhyackngrfhahetizpnnrmwzlgnrhvyfew", "fgismcxvchcvrbmfrdrnefvrweoujstqadjofimjroejrtqiyjxdouwnbnjkhcdkioypwkzqafzsyrcxccctyagznpmxuphcdhrbusruysowlrvotzhr", "cntrefoawvezfyczqutooinabkoukvnokifqnurlrvkwtpvmjrazbnzcypykmnyywdplzgxtdjrzynljgnjhdilbajnmwnluqagsidlnmemltzuzndiq", "ottqcicbvpvnrbfzgsptxdgqdassgaiwudmylqbggxtxabzhtoasrilwidoqfyobbacorduzcqwdrvmmloffwsdgxsxcslgwoikflfgovctoafanthsp", "zwvyqubkihgwrrdcyjsvnljnsldntveutatlwwwefeawvfavotqcgbrznwmgurcntvbrtzyydawbgxwwqpayquzfqmnkfqyanbtharhfsegyddwvsxtk", "rtqhhdsotsqjtjsvbzavfjtimrdgoxsfsinzohnjzfsuokprmrmrahcozfwneptyzixnpmxqrrkicbzoumhxtjnsrkivbducltscipubgejkhjybvgaq", "roliatgdwafjvxndohhxnqhuzixwqyphoaqovwrryycvwpbkyihlyrhazgypgnwupoikkbdkahgywhkwpujplsrkzqbffxavokhymnjourmtywppqzgd", "rynsoqytqaqemaeynpohgaagzqvpretkcidqbdlrfevrezqrpeaxhbegtbxmfqwhbbzcglvlpqdvrvoibogirmomnmyvexchaelhrgsiyxdqsrauhgcz", "stnihodnnhvnniweprmnopfjigdqohrjcetjsyxfhutvcrztimjzdoimwnenuvwxzrisphxwdsrgmrbwfkvkbfyzscmnxkmxburqcqnflgnxxptebppe", "unensqcpdooekfxoykujqjgqazweqninbmctfekiuzogglvexrnqavidxehnspcveeqjkctgdjnkviquzgmbbugabpqtfsqlziwjkpsoyfavpqsqyeta", "zacapsvwlnhkvdvhunvvuvsjokzmrtoqvrsklpjwcqixwggsvcpqzibpudclysbtlvfxkovmhglfmsxjwpbxxdnrirfilidxeiwozrdixqplkovgdwga", "bvujozrzhuynfuegmhqlzfxktssxoyxsttbhuvjcrhrwcveqeubezyqtsisjhpbclemfzvjrcbpgywydqcjsczlvjdesufvhjhnlcwegztpyppbirmau", "nnpwqvpmamulvjwzfaffwwfnmivduvzhiofajwplklzfuxebamiwinlwvhcrebapsgpdegrprqunnzpnlzlvnxukgwckzczrkrvrxogrecetbtjovumi", "tguzewmdblxnesecgktmpxhqtqhonvygdsihrumuhjhmdmqlylxnkhgfxptkkttpobyfxkzguiuzukltvkggrolrdhbpcweqzcxwpyflhzkbkxwhifpb", "tdsxmwoosthsxeqmfvxmvkphhmortetmjllvjajcvsusxmhcigqfqfmytcpmgkbryomhqyjlqfgpsptcvjhmrvmkxdxgoaxookvfkhsaoyqinjklvrxm", "olwmovsevpskbqrlxjmnkewzngkiajwoutalospmkkylapxzajmknimcrwntgjhceknvcfhopfarwxsyggjvrvxitmbbwkeautvzyenplnihkcisjrpa", "onkhznlxxpaukvtlaialylvknddywsamhmvjzgizxitieotgyvtwiqhwvmwrgzfolbzlhhmhqhpwvicvfvsoobmjnidthijvjkgtsuaibreybitgfnwt", "oiddtgzcqkxavfvnzxxaodyrluxshuoyetbxbcarnztifoxeluhbzhsmbselosjunmsopugevzmaqjhdfqfexzqbtwmjrxeejytauzepassqdzuirboo", "cgryddhuanymlrofstxtnplrofbfiqvnynlbssxvgwjtpxzkswfgnqxbyaigsftrugunzsihqrafobrjzwpmnoploztjfpazvuowowdepgmghdpjaevn", "unaimvtrmttiqhgegklvsxdbaskayipsvpdhnwbzswjkfqqlabjuymvzhibhqranifwvdxxxvghbwymybxsamqbvyecovedgjzbpxamshuvfukevhyxv", "qaqofteaxhgjhkygmmatgwbcghaphxlyybmfwrhwaofhafnotokcmlessehzeuzeymjufqqfgxpiecxyshaeugymngnrcnvabgvgynnflcprhmpzvrep", "ycdlkrepgbpjhmphaemnhceqqwpopvdpahcmagbihrrqfiyhmmuvqbljzdxoyceyjgnlpotyfkrnupuhdpewssfrvehvglwsujdjxzjflasgrmpvdtrx", "lyogcycilacfjgqghalsafysunpxjixugndklhuxhxeqfvymxkgzrhtlwklfsiaavfkjmfgtemljhjxgvdinkbahmnogvohtvtehymceynpixmossyfc", "ailovawtqdomxsvxeyecltkigbbyzicbqqrosohitvwsnsstqwvbpimxjpxizcmqsdektnunirfvjzqbxlcntqmefmnfobxieduyqqnyhuvsultryygs", "ovwuhlzxowhtbdtrtgrdcovwzpqznytbtsxcfybuwipxniohqhksvhrwwjwlhppdhofnnjjjtyhhgxoyfaschlzguxteokhyzonmxwxrueyceoalqunx", "gofalzgclnakenyblwufaujgklraffaltfohgulskleqadrlzosbkbivmbvrgxfcfvllrwfbjkrjplwqbotlrdgffewnddpiycwqabtjnnueyqubgqmz", "tveybdoegdphilxiossefoifffgnvvnosrptwdzdiqmqdlbsdvwjjgqolxegurxmkofjrgmbzyucjvuoqsxzzoqmnwvhpstzgaiziwahwukhrgwjbvja", "lboaxjhmbcnjeyinulwthgczpaiqwtsjugktqtftwvdatnppymkgsnhhnpxllpvhyfboaijwdozweomcawktlrczjckuthbroehpntlqhknlbbqbzcwl", "wzmfdybwgequlzjysxocjdpkgfmiikvgjhlohonnudkfetdxsuzezooiwcqgplmauzpbpcrlhbrnwwkrslvuclcaqsgffufbvwekavvhyoxxnhofvjzz", "wbzmvhtcbzdwvkiwfffgucdhmrojcqiytjnrqgttfzrdjzbqeiwanbjzsykwqsvjbictowmwvdbeccuiktjzusynsklieguhqwahumfprgvviseulpuf", "juuchgmloithftozitrzzmvjebfrqbxbytdfzsqqajxffnhngaoholstmxmebjgzdleeduuegtllguamuovjcpeqpqvqcdpfqvlwriazbnkiimwcdulf", "jrvyisqkvfrocckummtqzgyhuwmxszceryczqvjocccfeobtawjzejjzhvwauzelzikrdvfgxjnezoxzkizpriqydmaznglmpxeutlcsxpwwfvysdxjw", "hzvmnxlbewpvuvrphuhglgerbclhbudivawiyijcgzzcuqtdkblyhqpkucrwyxgtxfdxnnzvoyakrtqbwbzftqqoujmsiulgzpdoefkufmewhuaeyzlr", "sbhmntfvosdpjjepoojtcqsjmspktbelclarhfpxzsmjbqyrgkniafumxjzqkdepqegxlxwmqjvtbwliiasifmwewvwgycvpgeotblgtwdpxbchjcath", "mqnknjromodustowewpczeadghoijiryaeipqbdeqiykcogikylmclrlufvepncrtmhjqkngtosxczfpzqdbduoyzkerziisupekctsxhnummbbnseqv", "afvbrzsqhbkesqqwklvtyrfmtiznopkqwgsnhkdrnqvigneqyamwrtkmcjzsbkjxsblznqsbgpjndpfdprcjlmvpyxhzjswbvhcjavmgkvvpmbtesvnd", "jkshjcgsudvsmybovnvhkqxwrsampprycmiloogktbcibfwystgekfddzfrovjozvwmjnsviuasxfrwakcewjhciptwmcmlxlxiasgimgdlluhnelsdu", "bfeqyacdppcaplahtkvzngmhqaoburyxycqydubukgwzrwikidlwlzfbzvdvmbtmdlnifoerwasnwazhfmdrmksngxjuyejepwmwmrojtgyqjyzomefy", "oamuxxrwdaauwoqiherbnqtwqsmcwsbmspjpmanrcplygbipicqxslvkfhodzrqtgbludylfqwdwanlkpehjrctxjiclzugivrcysqdioieqypanvhxn", "jsmvcoielomggqhyimgxxmnvbokzxjmjcyegookzcwikppixdquackxgyifxttgvrmcfaofdlnnaeyxhqukvejbetibnbkkuwozxdgcqvrszprjilvdr", "ggxaqbptlznhoogtvijqabsrudzgaezgkzicaxvnxiwnxdgulpknsehmjgujnwszvacvyxkvggifjqzxflmzstlbcgnpcfozfqwfqgcymkdyaevhpjgh", "dujfcwugdifibbqrjspxduvfyspncxxftimvegbjqirtljmucduhxpovidlmdktwsfsynvhdgazrklompitozhmjlxvqhombvgziegokgndqarcpbveb", "dqkqpigyyuzudychgstmfwdiqfxtddwgvjymrgkpallflqorihgqgjyyqxrtdqbyzzlqfxhiltnylcstlylrhjrzhltkbwkawxsdvzniubgffybswmmf", "wdhfoarrwdrubjaylngfqonxpoqlcctahafycypachxdsxddkjldzaaoqscsuxtexacbzrbdyaitxlwkwjnvjpmziouelniknkloeorepzxmkuygflep", "dqqlekrrzabpmodscxxrwugjqerwsvnvnditqbkrdngqbmiejhxfcdoskgocddzrhjkzkxqokzgmlqsuypzcvqufyljdqkwzvjyhgrxsqdebwyxwoyyl", "ouqohbsylqxgzynfrnyhqekodjmthmeyjwmqxgqixqqwqfehseqlicbnloiuaoslkhehnurmmjleppnjtdwdhytuobpqqhccogkecdspndvesjpnmmtw", "moqaphqhrsmhayldbesqjnueymrlymjmabmsjebaznhzlvcnbwdkmaokmixmugyximptqqtpecrpxteaqknekboylmmiukfeyuxomqgqvziusmvkyiok", "lfiztwhniosgirxwifndexxylujkezuqgfpzbynkmhswypsiuhnaenzqhkamlwesbvrdvgphnhdoxxytfmujzvbifdwqacibxaeugvbwdgmcekvlyrwx", "myitbgkbjsfiulddhgbmpnovzlgyfcxrcflgoxjzpohmamphvsvkfjfewlcbpctuhgcxdlwucgicuzlprgzyrednrhpjjkftqhsvuprwvcypblhtrgri", "nwwgglrrxwmnffkaudwrfvihipcaytklsityvlrsjefpjrpfxnwckgltwnvujfhbocbjnsezylohdfoaumeftqyrdtnmaupqyqcmlgnjrdtukhweubjn", "tjewctlfnavntxbgdopvrirbqqimrrbmbfkfavknyiatfczjsogkzxnrnvdgpessldxlakaasctxgsizjolkoabdygknmehzjekmqmmkqgixasyjjlvx", "nyanemcqtjpeqbqgpdrglbflvfxeqsdfrgtxuvqpfhuvlkdapugcxlovsnzihfqyljyheoxlvrgidkjvgrxgflbxycgihwguhgcnuzzsqfavrlqadoii", "zlfannkxlsrsztgvufpmmqigdyigmsoodwqsjapxshrtcxpxeeltwtbasligdzwgvoygqodjxvebutabamwwfxyzihilggtdvtjljpwgkbkgwkhwwdte", "crfkanxguslrmvcvkbewcocyymvxpqdujiekwesswejibngnokjsanrazozrgclplrbjvwbucmcdzkqowbgwozxopwfvzsnmjqvfmwzqkdtjolzkmgjd", "hirxgyufqhtbyoimmhdwnygdmfpanydviwupuowmyqoyewmtgppvqxycfpcuqgryclnzcknccbagambietduqdyxucskijlnxaobkbdmffvhryrxrwti", "bthvwziglttitjjgnoustrbmqskhofrpzzmvaublpxvliervunpnfqaxkmgararszenbarnqqibypuwjhlxoezlqlureuixvokwpdlftuiulcqwlbvah", "unyhhrmdzjyqvvfzimucuopyemjijlrezpligzmiikyehffsrzunomnuawejkwnjlbtuafcjscpbhutytqnjcagcykliibtwenqeuupmwgqfajfwbshf", "unhsavdiywgclwigsauqgkvjwahxsqdmgmhgjkqjixluvwaoyweehcpfcyevphjvwqdhatrjsefqaheydkfmmwrpvwmkfxfboijqdcbwggmhpshtemft", "jzkevyqcvxglfrektfizowidqqyveeopdavaylctiihpzlassiugfcmvsksxqiovikxivaegklvmwvgogaxndlkxxdwonllwvjeqjiwvvuhrroixohkt", "svrraphnatlvcsoncmkygsryizxyiiscfluhabwbwiyyaoncbyajsujavhyersiydcfggbjcjhdlwqqzqsiimskizjosdwqjzvphyyjkhovfhlexepiq", "jsaidoahlsqmnhtlfevovtuceabkpjdycfifukohcetrlofsucjrvftcfvmxerxixiqtueazlvqylvthaczvjsxqpmpwfngcxwxrdxsqulofijninmew", "gdnwpcuvrazozxicwcsrniwwslefxicgmredtyalycbzblbxovqbenxwacdymfgawkesigdiigijslhihzjnmjlpnonzwvcufgmporzxyhgsvpaeplrd", "uesjshlqcnljvxyjrygrhplegnixybdvfveafrqjebtzbtlurtlbiwfrjoojrrexplxucpfjryiustolpzoxxuoikfrdwyanlzhppnyinjchesvttjrq", "fhyrorvnpxaaziqoxqymzcweurxncqfkadbouybmwcovmellxjzwlvchmaurszbuecjadmmbqdyejjrgurdhmfobhkscjvwpzhrcugdmjbrsmizgbenq", "ldrvnlxwgvnhdfkzlpluteofpnoqrdgdhzaumxtuugcxnoyadkwyqlefyuysxgxegxbuwupqcrqqfoqkapjrapyajwuidrplqqfmkwfmpvewlxhmmsdm", "hbosyjadcpqtfxhruoejjkgvhphthmhqnyinhisjaiehgmzcaflmptjxissrechtapjjabscmzjslkwnphbhdkgneyfkcoeeenngqikchtwseshvcjcf", "viuajzkloqqufdcwlmauhxonrwjvhncewxefyrsojikpomnbanwkmkxgiibrwewubabbttqdeauunhvpwtzjgzpqhsifwezzgabcwrfatzuiiryenznt", "yejiztnvzpxgraintppmqlvyfvesusnvywdxssvrhuzbujqpygbqtyqytvqqpflpconwiknqgnrawjpxpsplrgjmdccshnhldwhmixeomxqkghjyazjt", "hsfkwkcgxlrdibpqavhmsxyyfiwfjhaqafayreeppyuxzlqbgxpyunybxxigeiwgqyfhclyujsrkdjllialdomgljpupxswnrdxvqvpaqjkvswhbwugm", "goapduhbmfqfipdansadblawjjzhehukvwczqjceoumykpyxhbclocjxmigqpcckyglqpnvfkjfuygthhvuxxdullabcdgpdmcuesrlcarwyzphimcfj", "hbvvdyxieomtrgxjxknzdjzcagkokrxssunwtmezdquuytfvesuhdtmfcytmqsgkptgkillldghczozfiwpnrbutbpirhocwkkiuxufbaofbcehkcyzu", "ztpcizurqyqaiywgsdjsrowvuffzdgtezkgjkcaacqclrytjbeesuapohunkciqbtymfbmfdfjqwhlhkrlelntaupperawuvvgayuhdzquxzhflzqpkg", "kmazehsedmbaubyqkcscypbhwogpdtvnhvolcgriusiqvhgflyhjokqkyzbduwsbsgpwogeibpawyhejfnsvakialjefgyhahwwvedgfsgespkbvzvqz", "faatkgysgfsndqlkvtrpbxhrhiohdeilhkersejzmdoptbzrutgwqopyydhejrpqevhwzsxlvodrpeimxqiqexqdczhlqycuvjtwesizgnsytaktrujx", "tzcvylgolilgugdyynxhcqfvsrollxjewnzwzhnkqytmgykeljlpbskwjbhuasazgbvhjitbimnomztzigokzzgkcpfcihbqjxzsfsvqhketjztrgjdh", "ilrmbyplgqbppajvuendqrxzrsszbwimhzykypvggyvvagsvmfyczxbsrtrvrbhbahlaxhgfhdaijvfvcfxdfavwuornpaoskashjboqeoaolflqnjts", "jpqfdktvmhnwjffsitlnkldvtolgzfalwqsbcnwpvjlgrrzzkkowxtsqifyjmauitpkvcgmzsyglrfmdrbaqwujgzhqoimwdbiyerldlllwcsihjljci", "dlofugtctrfwagattgeeraikkpvwbxgekwlfdgjwyrsaxvtqdxwuzegjvehwbndokotnvclvtfvsaokfngamkivimdeqsjecaxrvbesxmnpodauqguct", "cxbrchhvrlzrkrolxgkjvayycsokosfspijuqqpjdocnhsbfalqvnovrglcudhpsqymipdtssxizpjgrwxmknjbuufqxpfrhegrvjkpbhxdyilpfkdry", "muugakdpsuyyapvkzkniisiqgxxqaoomjiulvxcptanwrkisuvaeqixyhuqhlfvwpphmoldjnsfecnwxlyddgabnxrwiyteqineyyihnanrdcncnlhqt", "iriflgpjzvbjighioqvqfovibzvohohphrwsxnewiffsnocbezumnpuqrreyhnppenjbanxivecisemyfgksxgioaomjbdyfqkgqxfaujcdbgrzlzmfw", "upludzeedejtormowmkfppgxgilfwqeqgrnlstqvzbrotferroxggfgmprunjyepptbhotfnwydrdjjwaidgpluhcouloadftgpjzwxxuapzkyvmgasx", "lmepdzdrzgxvoogpkdmggbfszcehfwfqklinklfmtejhspwevikbmrtlvzvavctfnbtaoaohgxoyomejwomihhwcgtddvylkzgkngywmxmmoyqzwgohp", "vfreawhvushvyukguguusiisajrgxyxtfpxflgcizjdzfogawcurlejlnculcrghifowlqemcjmhzujwwdnhjyvxdpkfisprxdniwtvycjhedrabwplg", "pgdsxpyfhnyesnooglmlwwpznrdlgorvuwqrloyudzyvopkxcyizuzajqdvyrovnllgybhtegtauimrnkbmfcoqusnslcqznbfldmehuyjrivkvgmjno", "yfjstddvtcixkvawajtatkiqugyipnzptkhmnljjptgzogyqrrqmdbdxjbiyphqkrxyeihnaavbodzhvszhvcmvlodmfmcrdzpjkwzmyunoynvthvcfx", "pclffzmrbdwcsfoqeaozoczdyukvwpulrfsyeerhhpmbvarbdfcrkbuivgfuyzhrhasnglxqbjrwjlzmscfcfbmbkrxirebaetnnfkdgvuefhdtahbcn", "cpominwbrybytrlybogzkmesqzszcwmfnctwpszhqbfjsqkvgsuqfaixccwebjlolfmdxmkpprahjmepfbfkbqhfsfktovkccwfbkrszitirfnikonwr", "dfxwljrbgbfjymmkdfknasghfouveqphwofhzzkfaqqacdlikvvmpetxsnuygjiczplyovernwrqbeylbvxrztouiisouaqtsdsgbyxourewvejxajqz", "cetkooziqrcixwpyuooohvmdzwczfsbjywvmkwxbozlnxclrtzhawwfwshxzbykzvfohclismwhjyscrtjsqfxozhlakkkkhsaownzozvxkvpmnkxhcf", "gsenehyorkxlmlhzkxafukblwqytxayftftzmtpffmtrxaqiyqpucsgyiethgunbzicndruidnzdorlojcilxqlfwepfyegzmlmpchzguyjkrwaaalnx", "byfacwfdancoypfbyejueuhvqhxsskqwivwmrbptouhpjoqjsbdyvktnuqfmcvikseylhqgyknnvdfexgjvdwqqqivcktnwltxzbnfzxvmsytyybjtef", "muvupahkpdyiaxjpekmzwgargysqtwxfqvcixjsmosurpgguqvvpdxgmvbcrxzwqwaatjufancrekzaawwratamrbqiyrgqojqhslpuatlednffjdxjy", "xxpynzyhipvrheluvguqtztigzsjydjvbbvqavzkkudubpoyxjpskibqjvbjykgblbuoxtajqedtvurudgmnrpfckimlssmgwguvcugsamnvgepjneyg", "tfignwrhrdnpmjmqgsigevekbttoztwtafbndsvwxkljuxbcsjiwgmhkicahyxcyedmhvjgvvterrgtlrehaqokatmirjmpnqdxnodikwpdpxxaqbiqt", "ycutpekaqcoihlwyqgimvneukelnodhpidizjvzbznkiaigqoodmejgonreexnvfqfebadcbtmktuqklhpxlyfbnxftwsobkwhlwkqafcmzzclmlcjwc", "oyrnfnjybmkxtywgoylqkmrozdadowffwzuemgcpsopmmnualftvumlvqlzgkglgfgkrmojgfyurlouwwntszenrsmyctliytvshlboqzkkmzekvtfpu", "jcmbpmdkzokvlecyfspgdbuehebajqwvskyjyctysgtfkxdssuyvvtbezcgjsdemncwmgrmaxhfkgjcyfcvbvwfxamgsrmhgofsxwgxwpfgwokutmswk", "oehpsnjjbqppvkousmsiraehkacwsbijhpazelkfebxbnlvgznqspwzzyeytfgcmyenerzkvajxquuywkoozkqziuzdbhhpflckfbwadfxtburzehodt", "eeeadhblpqscuehxcicjhynbpmfzalsepwetghgvxaxtfhshpvryteckqjjtuezkcefinlfnlfgsmzcbwvbpbdbtnnmhtmtvsygfllszqbrcctfyqhpr", "mslzfxjalcwddelopfnighmkcsitbzkpuxpbxacicyofczwtgjdnqqxtkimnjycdwtfttjdyhrflsbgzlkodcnwovkbhldmhzrcsafqjxywrzfqmreqt", "sohpzkwmpltocvjfcbqbzptzullnqdgkspbtbafqlahpxqwzrnbtcwuyhflzltjdknylnddydkpccmbuzepdajdkqojbjvgtiegxjjvowmqyysuxyjcz", "sfjjvumgptzxxhwhtrvpempegkcevgfomqzjllqcgrcebynuskjywacekglgnqwbjxkwkcyrwcxxbkrvucttcxxpeixtbvumsgielixhnueqgvlbzgwb", "dtsjepchkwtefdlqnizaddqjadmzjicnevykmbrxzmderowezvheaxnadcbmkebqbaanbtmcfshwifdhdkldjbgmdhzplcioeichcqkjitgryjabvohe", "pnruusliutwbcaigtspblxumixpdlwicjbygtjopfmqjpzpitglhegtofisqfcuqdswydmpizitqjkycrjjxrclwnfosjikochoiveswmmmvwkxpwjmn", "namahaurlfhnowxjaqgmcsjyfiobrcofeahmdcfojmdxibikroyvjhvoqlrjofqsiygnalbjagikjqvcftxqbtetexcuctpmtxztjcellmvueqzjmwbp", "rhiyemujhjvahxtsbzfmnajstidfgfuameyrqucyexynwuhyvmmjoxbhhgoqlkqaqqthkvhquhfrdmrzadkrdnaktpafbsfsiabtvklprrgxfzyidizi", "vzsoqvvsncmwcprxzepsvxpdxplcxkkujclczgwnlklpzenaiesebkjyzuazektppetonpdyzonyscabgthkfqigmlfqxzhmfbdssgssvgspktstobdt", "tnbfahxygfmlipgayyuvgpkrkdmyertygufhbdhjivxslfuldrgmgqfqvrqcklcqfhzjkguuctopyjceciqiavawmsawdcoklovwwssylhpksroubeec", "zganyaldcznpnllkdgkopcajvqfxujzvrzkpbvsfxhuksiwvojmdlmogdtfzcexvfhkifencnioiqndgwrlhezpjsviwbfrjpdrwjfywnoefbklxdwgh", "vwsnrbjuicdzfvvoavmpktulfflibrswpklinudywgzdbvtdqfscamofrbqsuiqkubskxxivehahetlvzdzzqphjqxclhuxbyrlvpvtvftcjnpgotgpl", "vwuovybctyerrroinhdsbidqxkesstdnsybnyesrcwkwpzeciiwlsabrmhkednrvnvkmzcfeasaqtgubotpitsahakldzeapbmddpkjrcjhvrezixoqs", "iqzickneqptscyxriginpskgwjovzhnizmscyigoxbizzfsjlbwcvjltsbouibeipymngsdevodwvwhhzglwpwpjafdigjsxiemqyruvfarbyzkzhvvw", "umfurlezuzwefivgzpbhrvipwuodrlzlxghqropmpnquvlaxdeeubomzkacbmdpljwcbmtpbhhwevybyehufxgehjijxnyixwmajgpmpykttjxtpeove", "wblfmwezwnwvbyejpsyodshmpbbvryzncnvolznkomfqmlzcdasguzujcygtwijaxeqidgssszkgkliolauhcpqgnzalhloepeoukjoeialtmvjzwdha", "uzgjaixhtlnkpehcnvgxwtskpblnfunbuvlueiezvtmmxtomoxmmqeyfgksnehqadbxjlbigwutupjiegusxbtchdxwjemmhqjqbmbkixfenoptvlnsm", "gwvltrvyejhwsaxgdjqaovpdmkaxyskeqhqkznkfwtbqvawykmbyjsdvddvbxhhqoxcpmmuihxydyubijeisxoqatldrskjiilywxufgsfjqanalrkfq", "yvquitncewlohjkgfrmxxwpzlpkecpvcnnwvhjynfjdmupubjhzgfohqgtwikrkxfjvostdaeioazjbiscqxrxpzslhdftcmexczsfzwppyoacxsenrv", "niuhudkbzpndopchwdfltezvgyokohibqeikivnhmamarphnsnantzjbyxnmexpuczgmwvvivhjowsdrhdeadnddkrrroinsjwegrzqphbffujwbmber", "ohubylupvjhfhmlbndswfxczgyavbemsohtoupdqanxibkjonblsaprhpucraqjoxefuvimvxjdytmpgpcbqruzgodzrtihtomnjxzfukivdxklommed", "hdlxilocvyvkkkthjyevjzaijlwxabajgngpyxtuxoghyzrjavglugtdrratuccdrlusknmhduodthovcuiwadbtvdnphpszcmtmbfvebmhwtxswrcur", "gynbbaslrlmwzfibmgfnspjlmdjggezmcmpfohsgsgcslmvzscokryygdhojnnxrcmzqurwoaainpdnhgbuzbuhfbvqrloipcjfwdendgvqvzddhhzgi", "tqpuninyyynahvzkzmnfhebijgpqfybyosubaicyirbpmaanmntvtwedevtjtwjjpflppnqxernttngfcbcwxizbeumztvjibwzqlporidkbqrissnqs", "vpvbmidffmpikobvgrmquzsmqagkpxeloaoakrhrfwapldmtuzjqybcqeictfhgujvwtmemuamjnryglzqbxtfpzotvvabrlyogluthwhskzqskpkooe", "tfdhzafbcwnamtngmufupptfhfxutlynrdwsebtiagioawxmscihrbpajmuczurqaqketemtkwimuhbnjjwcnnewzzazvsrvkcbdipzsmjhiqivzrubg", "hhejgfiezbbjfdonupigyppqxmpqiszsadbiilohmqssvjhpypyxepnbdfumztebwhmhsaogsjansifqxdpcsffvmzjlupprwbyqdoxyzzlthqkhvbjp", "gqlsswgmmvfkyfbbwazvznpjfbqdcbsltfdlclaogfaelbijbjedyvogwejbhbmajroldobltbsgfarglwlktzqsfbtochplafyftbrodjxiloqymcig", "dayjdtxgcotctuiovbdakakxodvbhgjkghvmatsejngfjqthrwhdyuapxwsecbokkmwmfqqqgwvrnrygngkoakdzivdmytzifxumqkdwianxroehuovw", "aavlxaxvtwfzwznmlqittxrklxthlqfnqcypcymyurxsskefdozwmsizpehcuoplrqctoprkgqdbdhgiwhgkzojqsssphkayactqtnacdddinjqlrwvs", "ngjhzdwinyipdbfwqiywldeanxlgtiaiplsopoyengusjboajpwxsczhzlpvtqdibxysmwxbettowjqiyofrqeasrqnngsvjqweeubfzwapujhckvhdn", "odfftusbnqnforjiuqjssambhpleyqsmuzupuotjgiquzbfvronjrzmyoafpqxbmwxcsovbwdtreuyznooyfnlgenltdiwqgwuzmrciwwzaszbgopete", "pzkckfiueabaucolgwheyjxxmdldhhhziudtzlpdnsfhutsdsbhqkepwjbztkjssdxneldkyvrgsnavfccxojmnuponzzhsefhjskvqgmyyzzvgdzdri", "qgffvshucbzhikbtfrbrqztrwzuvfngvwlcrfjnhmoqvarqflrzbsuuovojadpvzcasilipyyitzzlgkehnwbhmxxxzdpverxzzihrghzbiampnqyaoa", "kczhaampvrgssidbzjiylrazinsgoiialhjliwcfpiahqdirosrbjsdrfvyvfgvqqfdadfhsqjbiojaddtgnljgtegqkpmcftghylqqdarmocmtffaut", "jboqjecysefnmmlafbdfupvydrgltaecdsunyylrfrerfqrktvrompoqgudzxjdadapbybsduzvbromklfaywpqcjvdgejjhlyijbdpxekzvanfmsgmp" };
	string s = "oajgdkcokvfpdaslnmomrpgwitwdoku";

	//string lines[] = { "aaaa", "aaaa", "aaaa", "aaaa", "aaaa" };
	//string lines[] = { "aabb", "bbbb", "bbbb", "bbbb", "bbbb" };
	//string s = "aaaaaaaaaaaaaaaaaaab";
	vector<vector<char>> board;
	for (int i = 0; i <= 185; i++) {
		vector<char> line(lines[i].begin(), lines[i].end());
		board.push_back(line);
	}

	bool ret;
	clock_t begin, end;
	begin = clock();
	ret = exist(board, s);
	end = clock();
	cout << "output: " << ret << ", Time elapsed: " << double(diffclock(end, begin)) << " ms" << endl;

	begin = clock();
	ret = exist2(board, s);
	end = clock();
	cout << "output: " << ret << ", Time elapsed: " << double(diffclock(end, begin)) << " ms" << endl;

	return 0;
}
