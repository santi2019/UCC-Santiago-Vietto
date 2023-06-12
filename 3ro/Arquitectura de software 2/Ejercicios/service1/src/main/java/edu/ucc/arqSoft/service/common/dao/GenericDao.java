package edu.ucc.arqSoft.service.common.dao;

import java.io.Serializable;
import java.util.List;

public interface GenericDao<E, ID extends Serializable> {
	
	public void insert(E entity);
	
	public void saveOrUpdate(E entity);

	public void update(E entity);

	public void remove(E entity);

	public E load(ID key);

	public List<E> getAll();
	
}