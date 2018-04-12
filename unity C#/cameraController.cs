using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cameraController : MonoBehaviour {
    public float MouseSpeed = 20f;
    public float panBorderThickness = 10f;
    public Vector2 MouseLmit;

    public float scrollSpeed = 2f;
    public float MinY = 20f;
    public float MaxY = 60f;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
        Vector3 pos = transform.position;

       if(Input.GetKey("w")|| Input.mousePosition.y >= Screen.height-panBorderThickness)
        {
            pos.z += MouseSpeed * Time.deltaTime;
        }
        if (Input.GetKey("s") || Input.mousePosition.y <= Screen.height - panBorderThickness)
        {
            pos.z -= MouseSpeed * Time.deltaTime;
        }
        if (Input.GetKey("d") || Input.mousePosition.x >= Screen.width- panBorderThickness)
        {
            pos.x += MouseSpeed * Time.deltaTime;
        }
        if (Input.GetKey("a") || Input.mousePosition.x <= Screen.width - panBorderThickness)
        {
            pos.x -= MouseSpeed * Time.deltaTime;
        }
        float Scroll = Input.GetAxis("Mouse ScrollWheel");
        pos.y -= Scroll * scrollSpeed *100f* Time.deltaTime; 
        pos.x = Mathf.Clamp(pos.x, -MouseLmit.x, MouseLmit.x);
        pos.y = Mathf.Clamp(pos.y, MinY, MaxY);
        pos.z = Mathf.Clamp(pos.z, -MouseLmit.y,MouseLmit.y);
        transform.position = pos;
    }
}
