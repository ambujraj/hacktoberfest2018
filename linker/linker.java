import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class lab1{
	public static void main(String[] args) {
		//In order to use scanner and be an actual two pass linker, program assumes
		//that the entire input will be entered twice

		Scanner myscanner = new Scanner (System.in);
		int num_modules = myscanner.nextInt();

		//for symbol table
		HashMap<String, Integer> mymap = new HashMap<>();

		//for undefined symbols and their absolute address
		HashMap<Integer, String> undefined = new HashMap<>();

		//for keeping track of # of uses of symbols
		HashMap<String, Integer> count = new HashMap<>();

		//for keeping track of where (in which module) each variable is defined
		HashMap<String, Integer> symbModule = new HashMap<>();

		//to help determine if a variable definiton is out of the range of size of the module
		HashMap<String, Integer> altered = new HashMap<>();

		HashMap<String, Integer> multiply_defined = new HashMap<>();

		//for keeping track of base addresses for each module
		int[] mylist = new int[num_modules+1];

		//base address for module 1 is always 0
		mylist[1]=0;

		//pass #1 - find base address for each module and absolute address for each external symbol
		int total_mod_size=0;
		for(int i=1; i<=num_modules; i++) {
			//get number of definitions
			int num_def = myscanner.nextInt();

			//relative location and absolute location
			int relloc =0;
			int absloc =0;

			if(num_def != 0) {
				for(int j=1; j<=num_def; j++) {
					//read in the definitions
					String symbol = myscanner.next();
					symbModule.put(symbol, i);

					relloc = myscanner.nextInt();

					absloc=relloc + total_mod_size;

					if(mymap.containsKey(symbol)) {multiply_defined.put(symbol,0);}
					mymap.put(symbol, absloc);
					altered.put(symbol, 0);
					count.put(symbol, 0);
					}
							}

				skipUseList(myscanner);



			int module_size = myscanner.nextInt();

			//check to see if address in definition exceeds size of module
			for(String variable :symbModule.keySet()) {
				if(symbModule.get(variable)==i) {
					int absolute = mymap.get(variable);
					int relative = absolute - total_mod_size;
					if(relative>=module_size) {
						relative = module_size -1;
						absolute = relative + total_mod_size;
						mymap.put(variable, absolute);
						altered.put(variable, 1);
					}
				}
			}

			total_mod_size += module_size;

			//keep track of where the next module begins
			if(i<num_modules) {
			mylist[i+1] =total_mod_size;}


			skipTextLine(myscanner, module_size);
			}

		//end of first pass

		//array to hold absolute memory locations
		int [] memory = new int[total_mod_size];

		//to determine if multiple symbols are used in the same instruction in memory
		int [] mem_index_count = new int[total_mod_size];

		//pass #2 - use base address and actual output to generate a symbol table

		//ignore number of modules
		myscanner.nextInt();

		for(int i=1; i<=num_modules; i++) {
			//skip over definitions list - already used it in first pass
			skipDefinitions(myscanner);

			int num_uses = myscanner.nextInt();

			if(num_uses !=0) {
				for(int k=1; k<=num_uses; k++) {
					String external = myscanner.next();

					int check = myscanner.nextInt();


					while(check != -1) {

	//for the external variable in the use list, go directly to the memory array and update the address there minus the opcode
						int memory_index = mylist[i]+check;

						if(mymap.containsKey(external)) {
						memory[memory_index] = mymap.get(external);
						mem_index_count[memory_index]++;
						int update = count.get(external); update++; count.put(external, update);
						}
						else {
							memory[memory_index] =111;

							undefined.put(memory_index, external);
						}
						check = myscanner.nextInt();

					}
				}
			}

			//handling the actual text instructions of the program
			int num_text =myscanner.nextInt();
			for(int l=0; l<num_text; l++) {
				int text = myscanner.nextInt();
				int index = l+mylist[i];
				if(text%10 == 3) {
					text -= 3;
					text /= 10;
					text += mylist[i];
					memory[index] =text;
				}

				else if(text%10 == 4) {
					text -= text%10000;
					text /=10;
					text += memory[index];
					memory[index] =text;
				}


				else if(text%10==1){
					memory[index]=text*10;
				}
				else {
					text -= text%10;
					text /= 10;
					memory[index] =text;
				}


			}


	}
		//begin output
		System.out.println("Symbol Table");
		for(String symb : mymap.keySet()) {
			int b = mymap.get(symb);

			if(multiply_defined.containsKey(symb)) {

				if(altered.get(symb)==1) {

			System.out.println(symb+"="+b+" Error(#1): This variable is multiply defined; last value used. Error(#2): Definition exceeds module size; last word in module used. ");
				}

				else {
					System.out.println(symb+"="+b+" Error: This variable is multiply defined; last value used.");
				}
			}

			else {
				if(altered.get(symb)==1) {

					System.out.println(symb+"="+b+" Error: Definition exceeds module size; last word in module used.");
				}
				else {
				System.out.println(symb+"="+b);
				}
			}
		}
		System.out.println();
		System.out.println("Memory Map");
		for(int x=0; x<total_mod_size;x++) {
			if(memory[x]!= 1111) {
					int rem = memory[x]%1000;
				//6 digit number - we have an immediate
				 if(memory[x]>99999){
					//need to get rid of the two digits from the right
					memory[x] /= 10;
					memory[x] -= memory[x]%10;
					memory[x] /= 10;
					System.out.println(x+":    "+memory[x]);
				}


			else if(rem<=299 ) {
					if(mem_index_count[x]>1) {
						System.out.println(x+":    "+memory[x]+" Error: Multiple variables used in instruction; all but last ignored.");
					}
					else {
			System.out.println(x+":    "+memory[x]);
					}
				}


				else{
					memory[x]-=rem; memory[x]+=299;
					System.out.println(x+":    "+memory[x]+" Error: Absolute address exceed legal machine size; largest legal value used.");

				}
			}


			else {
				if(mem_index_count[x]>1) {
					System.out.println(x+":    "+memory[x]+" Error(#1): "+undefined.get(x)+" is not defined; 111 used. Error(#2): Multiple variables used in instruction; all but last ignored.");
				}
				else {
				System.out.println(x+":    "+memory[x]+" Error: "+undefined.get(x)+" is not defined; 111 used.");
				}
			}
		}
		System.out.println();
		//unused variables
		for(String s : count.keySet()) {
			int check = count.get(s);
			int mod=0;
			if(check ==0) {
				//find which module the variable was defined in
				/*for(int x=2; x<=num_modules; x++) {
					if(mymap.get(s)<mylist[x]) {
					 mod = x-1;
					}

					else {mod=x;}
				}
				*/
				mod = symbModule.get(s);mod--;
				System.out.println("Warning: "+s+" was defined in module number "+mod+" but never used.");
			}
		}

	}

	//function to skip over use list while using scanner
	public static void skipUseList(Scanner scanner) {
		int uses = scanner.nextInt();
		//System.out.println("uses = "+uses);
		if(uses ==0) {return;}
		String var = scanner.next();
		//System.out.println("var is "+var);
		int nums = scanner.nextInt();
		int counter =0;
		while (true) {
			//System.out.println("nums= "+nums);

			if(nums== -1) {counter++;if(counter<uses) {var = scanner.next();}}
			//System.out.println("counter= "+counter);
			if(counter==uses) {break;}
			nums = scanner.nextInt();
		}
		return;
	}

	//function to skip over definitions list while using scanner
	public static void skipDefinitions(Scanner scanner) {
		int definitions = scanner.nextInt();
		for(int i=1; i<=definitions; i++) {
			String var = scanner.next();
			int location = scanner.nextInt();
		}

					}
	//function to skip over the remainder of the text line after reading the first number (size)
	public static void skipTextLine(Scanner scanner, int size) {
		for(int i =1; i<=size; i++) {
			int check = scanner.nextInt();
		}
		return;
	}

	}
