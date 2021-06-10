import java.util.*;

class Instance{
	int cursor;
	String content;
	String clipBoard;
	public Instance() {
		cursor = 0;
		content = "";
		clipBoard ="";
	}
	public Instance(int cur, String cont, String clip) {
		cursor = cur;
		content = cont;
		clipBoard = clip;
		
	}
}
public class AssignmentNotePad {
	
	public static void exitCode() {
		System.exit(0);

	}
	private static String insertChar(String content, char inputChar, int cursor) {
		content = content.substring(0,cursor) + inputChar + content.substring(cursor);
		return content;
	}
	private static String deleteChar(int del,String content, int cursor) {
		if(del == 1)
			del = 0;
		content = content.substring(0,cursor+del) + content.substring(cursor+1+del);
		return content;
	}


	public static void main(String argv[]) {
		Instance instance = new Instance();
		Stack<Instance> stack = new Stack<Instance>();
		Stack<Instance> redoStack = new Stack<Instance>();

		Scanner scanner = new Scanner(System.in);
		String command;
		while(true) {
			command = scanner.next();
			System.out.println("the command is "+ command);
			if(!command.equals("UNDO") && !command.contentEquals("REDO"))
				redoStack.clear();
			if(command.equals("EXIT")) {
				exitCode();
			}
			else if (command.equals("PRINT")) {
				System.out.println(instance.content);
			}
			else if (command.equals("PRINT_CURSOR")) {
				System.out.println(instance.cursor);
			}
			else if (command.equals("INSERT")) {
				String c = scanner.next();
				if(c.length() != 1 )
				{
					System.out.println("wrong syntax!");
					continue;
				}
				stack.push(new Instance(instance.cursor, instance.content,instance.clipBoard));

				instance.content = insertChar(instance.content, c.charAt(0), instance.cursor);
				instance.cursor++;
			}
			else if (command.equals("SEEK")) {
				int seek = instance.cursor;
				try {
					seek = scanner.nextInt();
				}
				catch(Exception e) {
					System.out.println(e.getMessage());
					command = scanner.next();
					continue;
				}
				
				if(seek > instance.content.length() || seek < -1 ) {
					System.out.println("OUT OF BOUND!");
					continue;
				}
				if(seek == -1)
					seek =instance.content.length();
				stack.push(new Instance(instance.cursor, instance.content,instance.clipBoard));
				instance.cursor = seek;
			}
			else if (command.equals("DELETE")) {
				int del = 0;
				try {
					del = scanner.nextInt();
				}
				catch(Exception e) {
					System.out.println(e.getMessage());
					command = scanner.next();
					continue;
				}
				if(del == 1 && instance.cursor < instance.content.length()) {
					stack.push(new Instance(instance.cursor, instance.content,instance.clipBoard));
					instance.content = deleteChar(del,instance.content,instance.cursor);
				}
				else if(del == -1) {
					stack.push(new Instance(instance.cursor, instance.content,instance.clipBoard));
					instance.content = deleteChar(del,instance.content,instance.cursor);
					instance.cursor--;
				}
				else{
					System.out.println("NOT POSSIBLE");
					continue;
				}
				
				
			}
			else if (command.equals("COPY")) {
				int x,y;
				x = 0;
				y = 0;
				try {
					x = scanner.nextInt();
					y = scanner.nextInt();
				}
				catch(Exception e) {
					System.out.println(e.getMessage());
					command = scanner.next();
					continue;
				}
				
				if( x < y && x >= 0 && y < instance.content.length() ) {
					stack.push(new Instance(instance.cursor, instance.content,instance.clipBoard));

					instance.clipBoard = instance.content.substring(x,y);
				}
				else {
					System.out.println("OUT OF BOUND!");
					continue;
				}
				
			}
			else if (command.equals("PRINT_CLIPBOARD")) {
				System.out.println(instance.clipBoard);
				
			}
			else if (command.equals("CUT")) {
				int x,y;
				x = 0;
				y = 0;
				try {
					x = scanner.nextInt();
					y = scanner.nextInt();
				}
				catch(Exception e) {
					System.out.println(e.getMessage());
					command = scanner.next();
					continue;
				}
				
				if( x < y && x >= 0 && y < instance.content.length() ) {
					stack.push(new Instance(instance.cursor, instance.content,instance.clipBoard));
					instance.clipBoard = instance.content.substring(x,y);
					instance.content = instance.content.substring(0,x) + instance.content.substring(y);
				}
				else {
					System.out.println("OUT OF BOUND!");
					stack.push(new Instance(instance.cursor, instance.content,instance.clipBoard));
					instance.cursor = instance.content.length();
					continue;
				}
			}
			else if (command.equals("PASTE")) {
				int position = 0;
				try {
					position = scanner.nextInt();
				}
				catch(Exception e) {
					System.out.println(e.getMessage());
					command = scanner.next();
					continue;
				}
				
				if(position > instance.content.length() || position < 0 ) {
					System.out.println("OUT OF BOUND!");
					continue;
				}
				stack.push(new Instance(instance.cursor, instance.content,instance.clipBoard));
				instance.content = instance.content.substring(0,position) + instance.clipBoard + instance.content.substring(position);
				instance.cursor = position + instance.clipBoard.length();
			}
			else if (command.equals("UNDO")) {
				//System.out.print(stack.pop()
				redoStack.push(new Instance(instance.cursor, instance.content,instance.clipBoard));
				try {
						instance = stack.pop();
					}
				catch(Exception e) {
					instance = redoStack.pop();
					System.out.println("Nothing else to undo");
				}
				
			}
			else if (command.equals("REDO")) {
				stack.push(new Instance(instance.cursor, instance.content,instance.clipBoard));
				try {
					instance = redoStack.pop();
				}
				catch(Exception e) {
					instance = redoStack.pop();
					System.out.println("Nothing else to Redo");
				}
			}
			else if (command.equals("SAVE")) {
				
			}
			else if (command.equals("OPEN")) {
			}
			
		}
		
		
	
	}


}

