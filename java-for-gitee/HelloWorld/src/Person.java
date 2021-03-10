public class Person {
    String name;
    int id;

    @Override
    public String toString() {
        return "User{" +
                "name='" + name + '\'' +
                ", age=" + id +
                '}';
    }

    public static void main(String[] args) {
        Person user = new Person();
        user.name = "smith";
        user.id = 22;
        System.out.println(user);
    }

    private void myMethod() {
        System.out.println("hello world");
        System.out.println("hello world");
    }

    public void print(){
        myMethod();
    }
}


