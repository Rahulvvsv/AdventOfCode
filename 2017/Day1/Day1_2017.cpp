#include<iostream>

using namespace std;
int result1 = 0;
/*int  result(int nums){
	int quotient = nums/10;
	int remainder = nums%10;
	if( remainder == quotient%10){	
		result1 = result1 + remainder;
		result(quotient/10);}
	if( remainder != quotient%10){
		result(quotient);};
	if(quotient == 0){
		result1 = result1 + 0;
		return result1;}}*/
int main(){

char my_nums[] ="9514845965411415573169847814949991796797677476271324475131716264245617796628731577614429522122966855734523112634451632334931992113878384615946356666994229829477826233173336839784381232613268639597197771792285993193211389484665627437615848361845129841316353541162648991819527482245239539764858162952279457925557261219133449594544588294854711744157752788653241427333397898789295962759983417788738895858199164574747732522491793665999514541826572255762778346692229823668846885657546912737459594686489574985113262159343539639814715939846175545145196237853268883747421473189934232148347517859569583951334866563884545527697225625244157159138699463255513966385933987299385264249943482679351535558515522872233133835836699129413643446947254782582974989695176328811873941415934798185361945979765192542159322576537774552274776179578332734632165936423942152753147349147197266189231779183426643519542526672532338588143653517229387166215442265989562577532122488592583513631747827423369614253253815615759923524155141687828161738611488594782853395291516314295368192864987218123238617716385743444168794762559299291579129841517426132687547796853961259545953181349333666265944982499563887717237772427726546784488158445553728925747477356723682998265482547443593776672947645593346595232331465875682611162531551893941886968316912847112648729143489618882533869719944313524747173768787459487691712432426212199123787317555443872494439973823997147383518577523293679976651669564675444598175829154785144865414539321755984135542596721173648631125925159889227471648426683619251355512489234499683283858898775121569527251986917469514314434974964557615164865734761853217485236442834941811193998743246839223935476828519314359312762677667727982615631179546485764217413848234941878952725825756696852799869883577961387943261258527729954463557232111615231618862225628535464884115634739986338479532467875571461876969478313357228889181729612564989718689462372995234748419835273914899623571964339272517987643624939658949955926832966518747873842473266438867749668286573937176265915783211748322224341288178717653472781527994255656335211526436862214111294634254964253855167196828841574527721415857431666471919387279713662743578742521667217599";

char my_new_nums[] = "951484596541141557316984781494999179679767747627132447513171626424561779662873157761442952212296685573452311263445163233493199211387838461594635666699422982947782623317333683978438123261326863959719777179228599319321138948466562743761584836184512984131635354116264899181952748224523953976485816295227945792555726121913344959454458829485471174415775278865324142733339789878929596275998341778873889585819916457474773252249179366599951454182657225576277834669222982366884688565754691273745959468648957498511326215934353963981471593984617554514519623785326888374742147318993423214834751785956958395133486656388454552769722562524415715913869946325551396638593398729938526424994348267935153555851552287223313383583669912941364344694725478258297498969517632881187394141593479818536194597976519254215932257653777455227477617957833273463216593642394215275314734914719726618923177918342664351954252667253233858814365351722938716621544226598956257753212248859258351363174782742336961425325381561575992352415514168782816173861148859478285339529151631429536819286498721812323861771638574344416879476255929929157912984151742613268754779685396125954595318134933366626594498249956388771723777242772654678448815844555372892574747735672368299826548254744359377667294764559334659523233146587568261116253155189394188696831691284711264872914348961888253386971994431352474717376878745948769171243242621219912378731755544387249443997382399714738351857752329367997665166956467544459817582915478514486541453932175598413554259672117364863112592515988922747164842668361925135551248923449968328385889877512156952725198691746951431443497496455761516486573476185321748523644283494181119399874324683922393547682851931435931276267766772798261563117954648576421741384823494187895272582575669685279986988357796138794326125852772995446355723211161523161886222562853546488411563473998633847953246787557146187696947831335722888918172961256498971868946237299523474841983527391489962357196433927251798764362493965894995592683296651874787384247326643886774966828657393717626591578321174832222434128817871765347278152799425565633521152643686221411129463425496425385516719682884157452772141585743166647191938727971366274357874252166721759";
bool a = true;
char  ptr1 ;
char  ptr2 ;
int result =0;
cout << int(my_nums[219]) -48<<endl ;
for(int i = 0; i<2196;i++){
	
	int j ;
	if(i<2197/2){
		j  = i + 2196/2;
	}
	if( i>=2197/2){
		j = i-(2197/2) ;
	} 
	ptr1 = my_new_nums[i];
	ptr2 = my_new_nums[j];
	if(int(ptr1) == int(ptr2)){
		//cout<<result<<endl;
		result = result + (int(ptr1) - 48);
		result1 =result1+result;
		
	}
	else{
	continue;}
	
	
	
}

		
//int x = result(my_nums);
cout<<result1<<endl;
cout<<result<<endl;


return 0;
}