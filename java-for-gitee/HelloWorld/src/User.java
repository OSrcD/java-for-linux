public class User {

    String name;
    int age;

    @Override
    public String toString() {
        return "User{" +
                "name='" + name + '\'' +
                '}';
    }

    public User() {
        System.out.println("这是一个没有参数的构造方法");
    }

    public User(String name, int age) {
        this.name = name;
        this.age = age;
        System.out.println("这是一个带有参数的构造方法");
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public static void main(String[] args) {
        User user = new User();

    }
}
